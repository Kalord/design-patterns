#include <iostream>
#include <string>
#include <vector>

class Post
{
public:
	std::string title;
	std::string category;
	std::string content;
	std::string author;
	std::vector<std::string> tags;
	bool isAdverstingPost;

	Post(
		std::string title,
		std::string category,
		std::string content,
		std::string author,
		std::vector<std::string> tags,
		bool isAdverstingPost
	);

	Post() {}
};

class PostBuilder
{
private:
	Post* post;
public:
	PostBuilder* create()
	{
		this->post = new Post();
		return this;
	}

	PostBuilder* setTitle(std::string title)
	{
		this->post->title = title;
		return this;
	}

	PostBuilder* setCategory(std::string category)
	{
		this->post->category = category;
		return this;
	}

	PostBuilder* setContent(std::string content)
	{
		this->post->content = content;
		return this;
	}

	PostBuilder* setAuthor(std::string author)
	{
		this->post->author = author;
		return this;
	}

	PostBuilder* setTags(std::vector<std::string> tags)
	{
		this->post->tags = tags;
		return this;
	}

	PostBuilder* setAdverstingPost(bool value)
	{
		this->post->isAdverstingPost = value;
		return this;
	}

	Post* build()
	{
		Post* result = this->post;
		this->create();
		return result;
	}
};

class Director
{
private:
	PostBuilder* builder;
public:
	Director(PostBuilder* builder)
	{
		this->builder;
	}

	Post* createCleanPost()
	{
		this->builder->create();
		return this->builder->build();
	}

	Post* createDefaultPost()
	{
		this->builder->setTitle("LorenIpsum")->
			setContent("Text")->
			setAuthor("Admin")->
			setTags(std::vector<std::string>{"Hello", "World"});

		return this->builder->build();
	}

	Post* createPost(std::string content)
	{
		this->builder->setTitle("LorenIpsum")->
			setContent(content)->
			setAuthor("Admin")->
			setTags(std::vector<std::string>{"Hello", "World"});

		return this->builder->build();
	}
};

int main()
{
	//Работа со строителем напрямую
	PostBuilder builder;

	builder.create()->setTitle("Hello")->
		setContent("Hello");

	Post* one = builder.build();

	std::cout << "First post" << std::endl;
	std::cout << "Title: " << one->title << std::endl;
	std::cout << "Content: " << one->content << std::endl;

	delete one;

	//Работа со строителем через директора
	Director director(&builder);

	Post* two = director.createDefaultPost();
	std::cout << "Second post" << std::endl;
	std::cout << "Title: " << two->title << std::endl;
	std::cout << "Content: " << two->content << std::endl;
	std::cout << "Author: " << two->author << std::endl;

	delete two;

	Post* three = director.createPost("Hello");
	std::cout << "Third post" << std::endl;
	std::cout << "Title: " << three->title << std::endl;
	std::cout << "Content: " << three->content << std::endl;
	std::cout << "Author: " << three->author << std::endl;

	delete three;

	return 0;
}