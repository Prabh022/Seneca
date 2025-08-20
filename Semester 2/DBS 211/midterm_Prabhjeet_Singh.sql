CREATE TABLE inventory(
    product_id NUMBER(*, 0) PRIMARY KEY,
    product_name VARCHAR(100) NOT NULL UNIQUE,
    last_procured DATE DEFAULT (current_date - 1),
    stock_quantity NUMBER(3, 0) DEFAULT 1,
    cost_per_piece NUMBER(5, 2),
    perishable VARCHAR(1)
        CONSTRAINT perishable_check  CHECK (perishable IN ('Y', 'N'))
);

CREATE TABLE invoices(
    invoice_number VARCHAR(20),
    product_id NUMBER(*, 0),
    quantity_sold number(3, 0) DEFAULT 1 
    CONSTRAINT pk_invoices  PRIMARY KEY,
      CONSTRAINT quantity_sold_check CHECK (quantity_sold > 0),
    rate NUMBER(5, 2),
    payment_type VARCHAR(30),
    FOREIGN KEY ( product_id ) REFERENCES inventory(product_id) ON DELETE CASCADE
);

CREATE OR REPLACE VIEW vw_inventory_invoices AS
  SELECT invoices.invoice_number as invoice_number,
         inventory.product_id as product_id,
         inventory.product_name as product_name,
         TO_CHAR(inventory.last_procured, 'DAY, DD MON, YYYY') as last_procured,
         inventory.cost_per_piece * invoices.quantity_sold AS total_cost_price,
         invoices.rate * invoices.quantity_sold AS total_selling_price
  FROM inventory
  JOIN invoices
  ON inventory.product_id = invoices.product_id;
