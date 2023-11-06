#pragma once

class Skill
{
	private:
	int id;
	int proficiency_level;
	public:
		Skill()
		{
			id=0;
			proficiency_level=0;
		}
		Skill(int id, int proficiency_level)
		{
			this->id=id;
			this->proficiency_level=proficiency_level;
		}
		int get_id()
		{
			return id;
		}
		int get_proficiency_level()
		{
			return proficiency_level;
		}
		void set_id(int id)
		{
			this->id=id;
		}
		void set_proficiency_level(int proficiency_level)
		{
			this->proficiency_level=proficiency_level;
		}
};
class Resource
{
	private:
	int id;
	int availability;
	Skill skill;
	public:
		Resource()
		{
			id=0;
			availability=0;
		}
		Resource(int id, int availability, Skill skill)
		{
			this->id=id;
			this->availability=availability;
			this->skill=skill;
		}
		int get_id()
		{
			return id;
		}
		int get_availability()
		{
			return availability;
		}
		Skill get_skill()
		{
			return skill;
		}
		void set_id(int id)
		{
			this->id=id;
		}
		void set_availability(int availability)
		{
			this->availability=availability;
		}
		void set_skill(Skill skill)
		{
			this->skill=skill;
		}
};
class Task
{
	private:
	int id;
	int duration;
	int start_time;
	int* dependencies_id;
	Skill skill;
	public:
		Task()
		{
			id=0;
			duration=0;
			start_time=0;
			dependencies_id=nullptr;
		}
		Task(int id, int duration, int start_time, int* dependencies_id, Skill skill)
		{
			this->id=id;
			this->duration=duration;
			this->start_time=start_time;
			this->dependencies_id=dependencies_id;
			this->skill=skill;
		}
		int get_id()
		{
			return id;
		}
		int get_duration()
		{
			return duration;
		}
		int get_start_time()
		{
			return start_time;
		}
		int* get_dependencies_id()
		{
			return dependencies_id;
		}
		Skill get_skill()
		{
			return skill;
		}
		void set_id(int id)
		{
			this->id=id;
		}
		void set_duration(int duration)
		{
			this->duration=duration;
		}
		void set_start_time(int start_time)
		{
			this->start_time=start_time;
		}
		void set_dependencies_id(int* dependencies_id)
		{
			this->dependencies_id=dependencies_id;
		}
		void set_skill(Skill skill)
		{
			this->skill=skill;
		}		
	
};


class Node
{
	private:
	Task task;
	Node* next;
	public:
		Node()
		{
			next=nullptr;
		}
		Node(Task task)
		{
			this->task=task;
			next=nullptr;
		}
		Task get_task()
		{
			return task;
		}
		Node* get_next()
		{
			return next;
		}
		void set_task(Task task)
		{
			this->task=task;
		}
		void set_next(Node* next)
		{
			this->next=next;
		}
};
class Project
{
private:
	int id;
	int duration;
	Task* tasks;
	Resource* resources;
	Node* head;
	Node* tail;
public:
	Project()
	{

		id = 0;
		duration = 0;
		tasks = nullptr;
		head = nullptr;
		tail = nullptr;
		resources = nullptr;
	}
	Project(int id, int duration, Task* tasks, Node* head, Node* tail,Resource* resources)
	{
		this->id = id;
		this->duration = duration;
		this->tasks = tasks;
		this->head = head;
		this->tail = tail;
		this->resources = resources;
	}
	int get_id()
	{
		return id;
	}
	int get_duration()
	{
		return duration;
	}
	Task* get_tasks()
	{
		return tasks;
	}
	Resource* get_resources()
	{
		return resources;
	}
	void set_id(int id)
	{
		this->id = id;
	}
	void set_duration(int duration)
	{
		this->duration = duration;
	}
	void set_tasks(Task* tasks)
	{
		this->tasks = tasks;
	}
	void set_resources(Resource* resources)
	{
		this->resources = resources;
	}
		
	Node* get_head()
	{
		return head;
	}
	Node* get_tail()
	{
		return tail;
	}
	void set_head(Node* head)
	{
		this->head=head;
	}
	void set_tail(Node* tail)
	{
		this->tail=tail;
	}
};
