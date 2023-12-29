FROM crystallang/crystal:1.10.1-alpine AS build
COPY generator.cr ./
RUN crystal build --no-debug --release --static --stats -o generator generator.cr

FROM scratch
CMD [ "/generator" ]
COPY --from=build generator /generator
