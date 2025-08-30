const commentSchema = new schema({
    comment: String,
    author: String,
    date: Date,
});

commentSchema.add({ comments: [commentSchema] });
let Comment = mongoose.model('comments', commentSchema);

let commentChain = new Comment({
    comment: 'This is the first comment',
    author: 'Prabh',
    date: new Date(),
    comments: [
        {
            comment: 'This is a reply to the first comment',
            author: 'Kang',
            date:  new Date(),
            comments: [
                {
                    comment: 'This is a reply to the reply',
                    author: 'Prabh',
                    date: new Date(),
                    comments: [],
                },
            ],
        },
    ],
});
