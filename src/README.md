# libapi
`libapi` is used to build a well-defined schema for supporting both GraphQL and RESTful apis. The idea is inspired by GraphQL.
In most cases or in most companies, we choose one of them between GraphQL or RESTful style ot build APIs, actually both have their own good parts, what I want to do is mix up those good parts to provide a good solution to build APIs.

An typical GraphQL schema contains those components as below:
```GraphQL
type Query {
  // RootQuery
  //   - RootQuery Name: Returns Type
  // me is the root query name
  // User is the root query response type
  me: User
}

type Mutation {
  // Mutation
  //   - Mutation Name(Mutation Arguments): Response Type
  register(RegisterRequest!): RegisterReponse
}

type Subscription {
  // Subscription
  //    - Subscription field name: Response Type
  postCreated: Post
}
```

```RESTful
type Get {
  // Get
  //  - Name URL PATH QUERY STRING

}

```