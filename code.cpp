#include<iostream>
#include<string>
#include<vector>

using namespace std;

////一、简单工厂模式
//class COperation        //基类
//{
//public:
//	int m_nFirst;
//	int m_nSecond;
//	virtual double GetResult()
//	{
//		double dResult = 0;
//		return dResult;
//	}
//};
//class AddOperation :public COperation   //加法类
//{
//public:
//	virtual double GetResult()
//	{
//		return m_nFirst + m_nSecond;
//	}
//};
//class SubOperation :public COperation  //减法类
//{
//public:
//	virtual double GetResult()
//	{
//		return m_nFirst - m_nSecond;
//	}
//};
//class CCalculatorFactory    //工厂类
//{
//public:
//	static COperation* Create(char cOperator);
//};
//COperation* CCalculatorFactory::Create(char cOperator)
//{
//	COperation* oper;
//	switch (cOperator)
//	{
//	case'+':
//		oper = new AddOperation();
//		break;
//	case'-':
//		oper = new SubOperation();
//		break;
//	default:
//		oper = new AddOperation();
//		break;
//	}
//	return oper;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	COperation* op = CCalculatorFactory::Create('-');
//	op->m_nFirst = a;
//	op->m_nSecond = b;
//	cout << op->GetResult() << endl;
//	return 0;
//}

//二、策略模式
class COperation   //策略基类
{
public:
	int m_nFirst;
	int m_nSecond;
	virtual double GetResult()
	{
		double dResult = 0;
		return dResult;
	}
};
class AddOperation :public COperation     //策略具体类-加法类
{
public:
	AddOperation(int a, int b)
	{
		m_nFirst = a;
		m_nSecond = b;
	}
	virtual double GetResult()
	{
		return m_nFirst + m_nSecond;
	}
};
class Context
{
private:
	COperation* op;
public:
	Context(COperation* temp)
	{
		op = temp;
	}
	double GetResult()
	{
		return op->GetResult();
	}
};
int main()
{
	int a, b;
	char c;
	cin >> a >> b;
	cout << "请输入运算符：";
	cin >> c;
	switch (c)
	{
	case'+':
		Context * context = new Context(new AddOperation(a, b));
		cout << context->GetResult() << endl;
		break;
	default:
		break;
	}
	return 0;
}
//策略与工厂相结合
class COperation   //策略基类
{
public:
	int m_nFirst;
	int m_nSecond;
	virtual double GetResult()
	{
		double dResult = 0;
		return dResult;
	}
};
class AddOperation :public COperation     //策略具体类-加法类
{
public:
	AddOperation()
	{
		m_nFirst = 0;
		m_nSecond = 0;
	}
	AddOperation(int a, int b)
	{
		m_nFirst = a;
		m_nSecond = b;
	}
	virtual double GetResult()
	{
		return m_nFirst + m_nSecond;
	}
};

class Context
{
private:
	COperation* op;
public:
	Context(char cType)
	{
		switch (cType)
		{
		case'+':
			op = new AddOperation(3, 8);
			break;
		default:
			op = new AddOperation();
			break;
		}
	}
	double GetResult()
	{
		return op->GetResult();
	}
};
int main()
{
	int a, b;
	cin >> a >> b;
	Context* test = new Context('+');
	cout << test->GetResult() << endl;
	return 0;
}


////三、装饰模式
//class Person
//{
//private:
//	string m_strName;
//public:
//	Person(string strName)
//	{
//		m_strName = strName;
//	}
//	Person() {}
//	virtual void Show()
//	{
//		cout << "装扮的是：" << m_strName << endl;
//	}
//};
//class Finery :public Person     //装饰类
//{
//protected:
//	Person* m_component;
//public:
//	void Decorate(Person* component)
//	{
//		m_component = component;
//	}
//	virtual void Show()
//	{
//		m_component->Show();
//	}
//};
//class TShirt :public Finery
//{
//public:
//	virtual void Show()
//	{
//		cout << "T Shirts" << endl;
//		m_component->Show();
//	}
//};
//class BigTrouser :public Finery
//{
//public:
//	virtual void Show()
//	{
//		cout << "Big Trouser" << endl;
//		m_component->Show();
//	}
//};
//int main()
//{
//	Person* p = new Person("小李");
//	BigTrouser* bt = new BigTrouser();
//	TShirt* ts = new TShirt();
//
//	bt->Decorate(p);
//	ts->Decorate(bt);  //基类指针Pweson*指向派生类对象BigTrouser,会调用BigTrouser的Show()
//	ts->Show();
//	return 0;
//}


////四、代理模式
//class Interface     //定义接口
//{
//public:
//	virtual void Request() = 0;
//};
//class RealClass :public Interface    //真实类
//{
//public:
//	virtual void Request()
//	{
//		cout << "真实的请求" << endl;
//	}
//};
//class ProxyClass :public Interface   //代理类
//{
//private:
//	RealClass* m_realClass;
//public:
//	virtual void Request()
//	{
//		m_realClass = new RealClass();
//		m_realClass->Request();
//		delete m_realClass;
//	}
//};
//int main()
//{
//	ProxyClass* test = new ProxyClass();
//	test->Request();
//	return 0;
//}


////五、工厂方法模式
//class LeiFeng
//{
//public:
//	virtual void Sweep()
//	{
//		cout << "雷锋扫地" << endl;
//	}
//};
//class Student :public LeiFeng
//{
//public:
//	virtual void Sweep()
//	{
//		cout << "大学生扫地" << endl;
//	}
//};
//class Volenter :public LeiFeng
//{
//public:
//	virtual void Sweep()
//	{
//		cout << "志愿者" << endl;
//	}
//};
//class LeiFengFactory                    //工厂基类
//{
//public:
//	virtual LeiFeng* CreateLeiFeng()
//	{
//		return new LeiFeng();
//	}
//};
//class StudentFactory :public LeiFengFactory           //工厂具体类
//{
//public:
//	virtual Student* CreateStudent()
//	{
//		return new Student();
//	}
//};
//class VolenterFactory :public LeiFengFactory              //工厂具体类
//{
//public:
//	virtual Volenter* CreateVolenter()
//	{
//		return new Volenter();
//	}
//};
//int main()                //客户端
//{
//	LeiFengFactory* sf = new LeiFengFactory();
//	LeiFeng* s = sf->CreateLeiFeng();
//	s->Sweep();
//	delete sf;
//	delete s;
//	return 0;
//}

////六、原型模式
//class Prototype
//{
//private:
//	string m_strName;
//public:
//	Prototype(string strName) :m_strName(strName) {}
//	Prototype() { m_strName = ""; }
//	void Show()
//	{
//		cout << m_strName << endl;
//	}
//	virtual Prototype* Clone() = 0;
//};
//class ConcretePrototype1 :public Prototype
//{
//public:
//	ConcretePrototype1(string strName) :Prototype(strName) {};
//	ConcretePrototype1() {}
//	virtual Prototype* Clone()
//	{
//		ConcretePrototype1* p = new ConcretePrototype1();
//		*p = *this;
//		return p;
//	}
//};
//class ConcretePrototype2 :public Prototype
//{
//public:
//	ConcretePrototype2(string strName) :Prototype(strName) {};
//	ConcretePrototype2() {}
//	virtual Prototype* Clone()
//	{
//		ConcretePrototype2* p = new ConcretePrototype2();
//		*p = *this;
//		return p;
//	}
//};
//int main()
//{
//	ConcretePrototype1* test = new ConcretePrototype1("小王");
//	ConcretePrototype2* test2 = (ConcretePrototype2*)test->Clone();
//	test->Show();
//	test2->Show();
//	return 0;
//}

////七、模板方法模式
//class AbstractClass
//{
//public:
//	void Show()
//	{
//		cout << "我是" << GetName() << endl;
//	}
//protected:
//	virtual string GetName() = 0;
//};
//class Naruto :public AbstractClass
//{
//protected:
//	virtual string GetName()
//	{
//		return "naruto";
//	}
//};
//class OnePeace :public AbstractClass
//{
//protected:
//	virtual string GetName()
//	{
//		return  "onepeace";
//	}
//};
//int main()
//{
//	Naruto* man1 = new Naruto();
//	man1->Show();
//
//	OnePeace* man2 = new OnePeace();
//	man2->Show();
//
//	return 0;
//}

////八、外观模式
//class SubSysOne
//{
//public:
//	void MethodOne()
//	{
//		cout << "方法一" << endl;
//	}
//};
//class SubSysTwo
//{
//public:
//	void MethodTwo()
//	{
//		cout << "方法二" << endl;
//	}
//};
//class SubSysThree
//{
//public:
//	void MethodThree()
//	{
//		cout << "方法三" << endl;
//	}
//};
////外观类
//class Facade
//{
//private:
//	SubSysOne* sub1;
//	SubSysTwo* sub2;
//	SubSysThree* sub3;
//
//public:
//	Facade()
//	{
//		sub1 = new SubSysOne();
//		sub2 = new SubSysTwo();
//		sub3 = new SubSysThree();
//	}
//	~Facade()
//	{
//		delete sub1;
//		delete sub2;
//		delete sub3;
//	}
//	void FacedeMethod()
//	{
//		sub1->MethodOne();
//		sub2->MethodTwo();
//		sub3->MethodThree();
//	}
//};
//int main()
//{
//	Facade* test = new Facade();
//	test->FacedeMethod();
//	delete test;
//	return 0;
//}

////九、建造者模式
//class Product
//{
//private:
//	vector<string>m_product;
//public:
//	void Add(string strtemp)
//	{
//		m_product.push_back(strtemp);
//	}
//	void Show()
//	{
//		vector<string>::iterator p = m_product.begin();
//		while (p != m_product.end())
//		{
//			cout << *p << endl;
//			p++;
//		}
//	}
//};
//class Builder
//{
//public:
//	virtual void BuilderA() = 0;
//	virtual void BuilderB() = 0;
//	virtual Product* GetResult() = 0;
//};
//class ConcreteBuilder1 :public Builder
//{
//private:
//	Product* m_product;
//public:
//	ConcreteBuilder1()
//	{
//		m_product = new Product();
//	}
//	virtual void BuilderA()
//	{
//		m_product->Add("one");
//	}
//	virtual void BuilderB()
//	{
//		m_product->Add("two");
//	}
//	virtual Product* GetResult()
//	{
//		return m_product;
//	}
//};
//class ConcreteBuilder2 :public Builder
//{
//private:
//	Product* m_product;
//public:
//	ConcreteBuilder2()
//	{
//		m_product = new Product();
//	}
//	virtual void BuilderA()
//	{
//		m_product->Add("A");
//	}
//	virtual void BuilderB()
//	{
//		m_product->Add("B");
//	}
//	virtual Product* GetResult()
//	{
//		return m_product;
//	}
//};
//class Direct
//{
//public:
//	void Construct(Builder* temp)
//	{
//		temp->BuilderA();
//		temp->BuilderB();
//	}
//};
//int main()
//{
//	Direct* p = new Direct();
//	Builder* b1 = new ConcreteBuilder1();
//	Builder* b2 = new ConcreteBuilder2();
//
//	p->Construct(b1);
//	Product* pb1 = b1->GetResult();
//	pb1->Show();
//	p->Construct(b2);
//	Product* pb2 = b2->GetResult();
//	pb2->Show();
//
//	return 0;
//}
////例2
//class Person
//{
//public:
//	virtual void createHead() = 0;
//	virtual void createHand() = 0;
//	virtual void createBody() = 0;
//	virtual void createFoot() = 0;
//};
//class ThinPerson :public Person
//{
//public:
//	virtual void createHead()
//	{
//		cout << "thin head" << endl;
//	}
//	virtual void createHand()
//	{
//		cout << "thin hand" << endl;
//	}
//	virtual void createBody()
//	{
//		cout << "thin body" << endl;
//	}
//	virtual void createFoot()
//	{
//		cout << "thin foot" << endl;
//	}
//};
//class ThickPerson :public Person
//{
//public:
//	virtual void createHead()
//	{
//		cout << "thick head" << endl;
//	}
//	virtual void createHand()
//	{
//		cout << "thick hand" << endl;
//	}
//	virtual void createBody()
//	{
//		cout << "thick body" << endl;
//	}
//	virtual void createFoot()
//	{
//		cout << "thick foot" << endl;
//	}
//};
//class Direct
//{
//private:
//	Person* p;
//public:
//	Direct(Person* tmp) { p = tmp; }
//	void Create()
//	{
//		p->createBody();
//		p->createFoot();
//		p->createHand();
//		p->createHead();
//	}
//};
//int main()
//{
//	Person* pthick = new ThickPerson();
//	Person* pthin = new ThinPerson();
//	Direct* dthick = new Direct(pthick);
//	Direct* dthin = new Direct(pthin);
//
//	dthick->Create();
//	dthin->Create();
//
//	delete dthick;
//	delete dthin;
//	delete pthick;
//	delete pthin;
//	return 0;
//}

////第十、观察者模式
////例1
//class Secretary;
//class StockObserve
//{
//private:
//	string name;
//	Secretary* sub;
//public:
//	StockObserve(string strname, Secretary* strsub)
//	{
//		name = strname;
//		sub = strsub;
//	}
//	void Update()
//	{
//		cout << name << ": " << sub->action << "不要玩股票了，抓紧工作。" << endl;
//	}
//};
//class Secretary
//{
//private:
//	vector<StockObserve>observers;
//public:
//	string action;
//	void Add(StockObserve ob)
//	{
//		observers.push_back(ob);
//	}
//	void Notify()
//	{
//		vector<StockObserve>::iterator iter = observers.begin();
//		while (iter != observers.end())
//		{
//			(*iter).Update();
//			iter++;
//		}
//	}
//};
//int main()
//{
//	Secretary* p = new Secretary();
//
//	StockObserve* s1 = new StockObserve("小赵", p);
//	StockObserve* s2 = new StockObserve("小李", p);
//
//	p->Add(*s1);
//	p->Add(*s2);
//
//	p->action = "老板来了";
//	p->Notify();
//
//	return 0;
//}
//例2
//class SecretaryBase;
//class CObserveBase
//{
//protected:
//	string name;
//	SecretaryBase* sub;
//public:
//	CObserveBase(string strname, SecretaryBase* strsub)
//	{
//		name = strname;
//		sub = strsub;
//	}
//	virtual void Update() = 0;
//};
//class StockObserve :public CObserveBase
//{
//public:
//	StockObserve(string strname, SecretaryBase* strsub) :CObserveBase(strname, strsub)
//	{
//
//	}
//	virtual void Update()
//	{
//		cout << name << sub->action << "不要玩股票" << endl;
//	}
//};
//class NBAObserve :public CObserveBase
//{
//public:
//	NBAObserve(string strname, SecretaryBase* strsub) :CObserveBase(strname, strsub)
//	{
//
//	}
//	virtual void Update()
//	{
//		cout << name << sub->action << "不要看NBA" << endl;
//	}
//};
//class SecretaryBase         //抽象通知者
//{
//public:
//	string action;
//	vector<CObserveBase*>observers;
//
//public:
//	virtual void Attach(CObserveBase* observer) = 0;
//	virtual void Notify() = 0;
//};
//class Secretary :public SecretaryBase     //具体通知者
//{
//public:
//	virtual void Attach(CObserveBase* observer)
//	{
//		observers.push_back(observer);
//	}
//	virtual void Notify()
//	{
//		vector<CObserveBase*>::iterator iter = observers.begin();
//		while (iter != observers.end())
//		{
//			(*iter)->Update();
//			iter++;
//		}
//	}
//};
//int main()
//{
//	SecretaryBase* s = new Secretary();
//
//	CObserveBase* c1 = new NBAObserve("小李", s);
//	CObserveBase* c2 = new StockObserve("小赵", s);
//
//	s->Attach(c1);
//	s->Attach(c2);
//
//	s->action = "老板来了";
//
//	s->Notify();
//
//	return 0;
//}

////十一、抽象工厂模式
//class IUser
//{
//public:
//	virtual void GetUser() = 0;
//	virtual void InsertUser() = 0;
//};
//class IDepartment
//{
//public:
//	virtual void GetDepartment() = 0;
//	virtual void InsertDepartment() = 0;
//};
//class CAccessUser :public IUser
//{
//public:
//	virtual void GetUser()
//	{
//		cout << "Access GetUser" << endl;
//	}
//	virtual void InsertUser()
//	{
//		cout << "Access InsertUser" << endl;
//	}
//};
//class CAccessDepartment:public IDepartment
//{
//public:
//	virtual void GetDepartment()
//	{
//		cout << "Access GetDepartment" << endl;
//	}
//	virtual void InsertDepartment()
//	{
//		cout << "Access InsertDepartment" << endl;
//	}
//};
//class CSqlUser :public IUser
//{
//public:
//	virtual void GetUser()
//	{
//		cout << "Sql GetUser" << endl;
//	}
//	virtual void InsertUser()
//	{
//		cout << "Sql InsertUser" << endl;
//	}
//};
//class CSqlDepartment :public IDepartment
//{
//public:
//	virtual void GetDepartment()
//	{
//		cout << "Sql GetDepartment" << endl;
//	}
//	virtual void InsertDepartment()
//	{
//		cout << "Sql InsertDepartment" << endl;
//	}
//};
//class IFactory
//{
//public:
//	virtual IUser* CreateUser() = 0;
//	virtual IDepartment* CreateDepartment() = 0;
//};
//class IAccessFactory :public IFactory
//{
//public:
//	virtual IUser* CreateUser()
//	{
//		return new CAccessUser();
//	}
//	virtual IDepartment* CreateDepartment()
//	{
//		return new CAccessDepartment();
//	}
//};
//class ISqlFactory :public IFactory
//{
//public:
//	virtual IUser* CreateUser()
//	{
//		return new CSqlUser();
//	}
//	virtual IDepartment* CreateDepartment()
//	{
//		return new CSqlDepartment();
//	}
//};
//int main()
//{
//	IFactory* factory = new ISqlFactory();
//	IUser* user = factory->CreateUser();
//	IDepartment* depart = factory->CreateDepartment();
//	user->GetUser();
//	depart->GetDepartment();
//	return 0;
//}

////十二、状态模式
//class Work;
//class ForenoonState;
//class NoonState;
//
//class State
//{
//public:
//	virtual void WriteProgram(Work* w) = 0;
//};
//class Work
//{
//private:
//	State* current;
//public:
//	double hour;
//	Work();
//	void SetState(State* temp)
//	{
//		current = temp;
//	}
//	void WriteProgram()
//	{
//		current->WriteProgram(this);
//	}
//};
//class NoonState :public State
//{
//public:
//	virtual void WriteProgram(Work* w)
//	{
//		cout << "execute" << endl;
//		if (w->hour < 13)
//			cout << "还不错啦" << endl;
//		else
//			cout << "不行了，还是睡觉吧" << endl;
//	}
//};
//class ForenoonState :public State
//{
//public:
//	virtual void WriteProgram(Work* w)
//	{
//		if (w->hour < 12)
//			cout << "现在精神无敌好" << endl;
//		else
//		{
//			w->SetState(new NoonState());
//			w->WriteProgram();
//		}
//	}
//};
//Work::Work()
//{
//	current = new ForenoonState();
//}
//
//int main()
//{
//	Work* mywork = new Work();
//	mywork->hour = 9;
//	mywork->WriteProgram();
//	mywork->hour = 14;
//	mywork->WriteProgram();
//	return 0;
//}

////十三、适配器模式
////例一
//class Target
//{
//public:
//	virtual void Request()
//	{
//		cout << "普通的请求" << endl;
//	}
//};
//class Adaptee
//{
//public:
//	void SpecificalRequest()
//	{
//		cout << "特殊请求" << endl;
//	}
//};
//class Adapter :public Target
//{
//private:
//	Adaptee* ada;
//public:
//	virtual void Request()
//	{
//		ada->SpecificalRequest();
//		Target::Request();
//	}
//	Adapter()
//	{
//		ada = new Adaptee();
//	}
//	~Adapter()
//	{
//		delete ada;
//	}
//};
//int main()
//{
//	Adapter* ada = new Adapter();
//	ada->Request();
//	delete ada;
//	return 0;
//}
////例二
//class  Player
//{
//protected:
//	string name;
//public:
//	Player(string strname)
//	{
//		name = strname;
//	}
//	virtual void Attack() = 0;
//	virtual void Defense() = 0;
//};
//class Forwards :public Player
//{
//public:
//	Forwards(string strname) :Player(strname) {}
//	virtual void Attack()
//	{
//		cout << name << "前锋进攻" << endl;
//	}
//	virtual void Defense()
//	{
//		cout << name << "前锋防守" << endl;
//	}
//};
//class Center :public Player
//{
//public:
//	Center(string strname) :Player(strname) {}
//	virtual void Attack()
//	{
//		cout << name << "中场进攻" << endl;
//	}
//	virtual void Defense()
//	{
//		cout << name << "中场防守" << endl;
//	}
//};
//class TransLater :public Player
//{
//private:
//	Center* player;
//public:
//	TransLater(string strname) :Player(strname)
//	{
//		player = new Center(strname);
//	}
//	virtual void Attack()
//	{
//		player->Attack();
//	}
//	virtual void Defense()
//	{
//		player->Defense();
//	}
//};
//int main()
//{
//	Player* p = new TransLater("小李");
//	p->Attack();
//	return 0;
//}

////十四、备忘录模式
//class Memo;
//class Originator
//{
//public:
//	string state;
//	Memo* CreateMemo();
//	void SetMemo(Memo* Memo);
//	void Show()
//	{
//		cout << "状态：" << state << endl;
//	}
//};
//class Memo
//{
//public:
//	string state;;
//	Memo(string strState)
//	{
//		state = strState;
//	}
//};
//Memo* Originator::CreateMemo()
//{
//	return new Memo(state);
//}
//void Originator::SetMemo(Memo* Memo)
//{
//	state = Memo->state;
//}
//class Caretaker
//{
//public:
//	Memo* memo;
//};
//int main()
//{
//	Originator* on = new Originator();
//	on->state = "on";
//	on->Show();
//
//	Caretaker* c = new Caretaker();
//	c->memo = on->CreateMemo();
//
//	on->state = "off";
//	on->Show();
//
//	on->SetMemo(c->memo);
//	on->Show();
//	return 0;
//}

////十五、组合模式
////例1
//class Component
//{
//public:
//	string m_strName;
//	Component(string strName)
//	{
//		m_strName = strName;
//	}
//	virtual void Add(Component* comp) = 0;
//	virtual void Display(int nDepth) = 0;
//};
//class Leaf :public Component
//{
//public:
//	Leaf(string strName) :Component(strName) {};
//	virtual void Add(Component* comp)
//	{
//		cout << "leaf cannot add" << endl;
//	}
//	virtual void Display(int nDepth)
//	{
//		string strTemp;
//		for (int i = 0; i < nDepth; i++)
//		{
//			strTemp += "-";
//		}
//		strTemp += m_strName;
//		cout << strTemp << endl;
//	}
//};
//class Composite :public Component
//{
//private:
//	vector<Component*>m_component;
//
//public:
//	Composite(string strName) :Component(strName) {}
//	virtual void Add(Component* comp)
//	{
//		m_component.push_back(comp);
//	}
//	virtual void Display(int nDepth)
//	{
//		string strTemp;
//		for (int i = 0; i < nDepth; i++)
//		{
//			strTemp += "-";
//		}
//		strTemp += m_strName;
//		cout << strTemp << endl;
//		vector<Component*>::iterator iter = m_component.begin();
//		while (iter != m_component.end())
//		{
//			(*iter)->Display(nDepth + 2);
//			iter++;
//		}
//	}
//};
//int main()
//{
//	Composite* p1 = new Composite("小王");
//	p1->Add(new Leaf("小李"));
//	p1->Add(new Leaf("小赵"));
//
//	Composite* p2 = new Composite("小小五");
//	p2->Add(new Leaf("大三"));
//
//	p1->Add(p2);
//	p1->Display(1);
//	return 0;
//}
////例2
//class Company
//{
//protected:
//	string m_strName;
//public:
//	Company(string strName)
//	{
//		m_strName = strName;
//	}
//	virtual void Add(Company* c) = 0;
//	virtual void Display(int nDepth) = 0;
//	virtual void LineOfDuty() = 0;
//};
//class ConcreteCompany :public Company
//{
//private:
//	vector<Company*>m_company;
//public:
//	ConcreteCompany(string strName) :Company(strName) {};
//	virtual void Add(Company* c)
//	{
//		m_company.push_back(c);
//	}
//	virtual void Display(int nDepth)
//	{
//		string strTemp;
//		for (int i = 0; i < nDepth; i++)
//		{
//			strTemp += "-";
//		}
//		strTemp += m_strName;
//		cout << strTemp << endl;
//		vector<Company*>::iterator iter = m_company.begin();
//		while (iter != m_company.end())
//		{
//			(*iter)->Display(nDepth + 2);
//			iter++;
//		}
//	}
//	virtual void LineOfDuty()
//	{
//		vector<Company*>::iterator iter = m_company.begin();
//		while (iter != m_company.end())
//		{
//			(*iter)->LineOfDuty();
//			iter++;
//		}
//	}
//};
//class HrDepartment :public Company
//{
//public:
//	HrDepartment(string strName) :Company(strName) {}
//	virtual void Add(Company* c)
//	{
//		cout << "error" << endl;
//	}
//	virtual void Display(int nDepth)
//	{
//		string strTemp;
//		for (int i = 0; i < nDepth; i++)
//		{
//			strTemp += "-";
//		}
//		strTemp += m_strName;
//		cout << strTemp << endl;
//	}
//	virtual void LineOfDuty()
//	{
//		cout << m_strName << "招聘人才： " << endl;
//	}
//};
//int main()
//{
//	ConcreteCompany* p = new ConcreteCompany("清华大学");
//	p->Add(new HrDepartment("清华大学人才部"));
//
//	ConcreteCompany* p1 = new ConcreteCompany("数学系");
//	p1->Add(new HrDepartment("数学系人才部"));
//
//	ConcreteCompany* p2 = new ConcreteCompany("物理系");
//	p2->Add(new HrDepartment("物理系人才部"));
//
//	p->Add(p1);
//	p->Add(p2);
//
//	p->Display(1);
//	p->LineOfDuty();
//
//	return 0;
//}

//十六、迭代器模式-----------没有例子
//提供一种方法顺序访问一个聚敛对象的各个元素，而又不暴露该对象的内部表示

////十七、单例模式
////保证一个类仅有一个实例，并提供一个访问它的全局访问点
//class Singelton
//{
//private:
//	Singelton() {}                       //默认构造函数为私有成员
//	static Singelton* singel; 
//public:
//	static Singelton* GetInstance()
//	{
//		if (singel == nullptr)
//		{
//			singel = new Singelton();
//		}
//		return singel;
//	}
//};
//Singelton* Singelton::singel = nullptr;   //静态成员对象，类外初始化
//
//int main()
//{
//	Singelton* s1 = Singelton::GetInstance();
//	Singelton* s2 = Singelton::GetInstance();
//	if (s1 == s2)
//		cout << "ok" << endl;
//	else
//		cout << "no" << endl;
//	return 0;
//}

////十八、桥接模式
//class HandsetSoft
//{
//public:
//	virtual void Run() = 0;
//};
//class HandsetGame :public HandsetSoft
//{
//public:
//	virtual void Run()
//	{
//		cout << "运行手机游戏" << endl;
//	}
//};
//class HandsetAddressList :public HandsetSoft
//{
//public:
//	virtual void Run()
//	{
//		cout << "运行通讯录游戏" << endl;
//	}
//};
//class HandsetBrand
//{
//protected:
//	HandsetSoft* m_soft;
//public:
//	void SetHandsetSoft(HandsetSoft* soft)
//	{
//		m_soft = soft;
//	}
//	virtual void Run() = 0;
//};
//class HandsetBrandM :public HandsetBrand
//{
//public:
//	virtual void Run()
//	{
//		m_soft->Run();
//	}
//};
//class HandsetBrandN :public HandsetBrand
//{
//public:
//	virtual void Run()
//	{
//		m_soft->Run();
//	}
//};
//int main()
//{
//	HandsetBrand* brand = new HandsetBrandM();
//	brand->SetHandsetSoft(new HandsetGame());
//	brand->Run();
//
//	brand->SetHandsetSoft(new HandsetAddressList());
//	brand->Run();
//
//	return 0;
//}

////十九、命令模式
//class Barbucer
//{
//public:
//	void MakeMutton()
//	{
//		cout << "烤羊肉" << endl;
//	}
//	void MakeChickenWing()
//	{
//		cout << "烤鸡翅膀" << endl;
//	}
//};
//class Command
//{
//protected:
//	Barbucer* receiver;
//public:
//	Command(Barbucer* temp)
//	{
//		receiver = temp;
//	}
//	virtual void ExecuteCmd() = 0;
//};
//class BakeMuttonCmd :public Command
//{
//public:
//	BakeMuttonCmd(Barbucer* temp) :Command(temp) {}
//	virtual void ExecuteCmd()
//	{
//		receiver->MakeMutton();
//	}
//};
//class ChickenWingCmd :public Command
//{
//public:
//	ChickenWingCmd(Barbucer* temp) :Command(temp) {}
//	virtual void ExecuteCmd()
//	{
//		receiver->MakeChickenWing();
//	}
//};
//class Waiter
//{
//protected:
//	vector<Command*>m_commandList;
//public:
//	void SetCmd(Command* temp)
//	{
//		m_commandList.push_back(temp);
//		cout << "增加订单" << endl;
//	}
//	void Notify()
//	{
//		vector<Command*>::iterator p = m_commandList.begin();
//		while (p != m_commandList.end())
//		{
//			(*p)->ExecuteCmd();
//			p++;
//		}
//	}
//};
//int main()
//{
//	Barbucer* barbucer = new Barbucer();
//	Command* cmd1 = new BakeMuttonCmd(barbucer);
//	Command* cmd2 = new ChickenWingCmd(barbucer);
//	Waiter* girl = new Waiter();
//
//	girl->SetCmd(cmd1);
//	girl->SetCmd(cmd2);
//	girl->Notify();
//
//	return 0;
//}
//
////第二十、责任链模式
//class Request
//{
//public:
//	string m_strContent;
//	int m_nNumber;
//};
//class Manager      //管理者
//{
//protected:
//	Manager* manager;
//	string name;
//public:
//	Manager(string temp)
//	{
//		name = temp;
//	}
//	void SetSuccessor(Manager* temp)
//	{
//		manager = temp;
//	}
//	virtual void GetRequest(Request* request) = 0;
//};
//class CommonManager :public Manager   //经理
//{
//public:
//	CommonManager(string strTemp) :Manager(strTemp) {}
//	virtual void GetRequest(Request* request)
//	{
//		if (request->m_nNumber >= 0 && request->m_nNumber < 10)
//		{
//			cout << name << "处理了" << request->m_nNumber << "个请求" << endl;
//		}
//		else
//		{
//			manager->GetRequest(request);
//		}
//	}
//};
//class MajorDomo :public Manager    //总监
//{
//public:
//	MajorDomo(string name):Manager(name){}
//	virtual void GetRequest(Request* request)
//	{
//		if (request->m_nNumber >= 10)
//		{
//			cout << name << "处理了" << request->m_nNumber << "个请求" << endl;
//		}
//	}
//};
//int main()
//{
//	Manager* common = new CommonManager("张经理");
//	Manager* major = new MajorDomo("李总监");
//	common->SetSuccessor(major);
//	Request* req = new Request();
//	req->m_nNumber = 33;
//	common->GetRequest(req);
//	req->m_nNumber = 3;
//	common->GetRequest(req);
//	return 0;
//}
//
////第二十一、中介者模式
//class Colleague;
//class Mediator   //中介者类
//{
//public:
//	virtual void Send(string message, Colleague* col) = 0;
//};
//class Colleague   //抽象同事类
//{
//protected:
//	Mediator* mediator;
//public:
//	Colleague(Mediator* temp)
//	{
//		mediator = temp;
//	}
//};
//class Colleague1 :public Colleague  //同事1
//{
//public:
//	Colleague1(Mediator* media) :Colleague(media) {}
//	void Send(string strMessage)
//	{
//		mediator->Send(strMessage, this);
//	}
//	void Notify(string strMessage)
//	{
//		cout << "同事一获得了消息" << strMessage << endl;
//	}
//};
//class Colleague2 :public Colleague   //同事2
//{
//public:
//	Colleague2(Mediator* media) :Colleague(media) {}
//	void Send(string strMessage)
//	{
//		mediator->Send(strMessage, this);
//	}
//	void Notify(string strMessage)
//	{
//		cout << "同时二获得了消息" << strMessage << endl;
//	}
//};
//class ConcreteMediator :public Mediator   //具体中介类
//{
//public:
//	Colleague1* col1;
//	Colleague2* col2;
//	virtual void Send(string message, Colleague* col)
//	{
//		if (col == col1)
//			col2->Notify(message);
//		else
//			col1->Notify(message);
//	}
//};
//int main()
//{
//	ConcreteMediator* m = new ConcreteMediator();
//
//	Colleague1* col1 = new Colleague1(m);
//	Colleague2* col2 = new Colleague2(m);
//
//	m->col1 = col1;
//	m->col2 = col2;
//
//	col1->Send("吃饭了吗");
//	col2->Send("还没吃，你请吗");
//
//	return 0;
//}
//
////第二十二、享元模式
//class WebSite     //抽象的网站
//{
//public:
//	virtual void Use() = 0;
//};
//class ConcreteWebSite :public WebSite   //具体的共享的网站
//{
//private:
//	string name;
//public:
//	ConcreteWebSite(string strName)
//	{
//		name = strName;
//	}
//	virtual void Use()
//	{
//		cout << "网站分类：" << name << endl;
//	}
//};
//class UnShareWebSite :public WebSite     //不共享的网站
//{
//private:
//	string name;
//public:
//	UnShareWebSite(string strName)
//	{
//		name = strName;
//	}
//	virtual void Use()
//	{
//		cout << "不共享的网站：" << name << endl;
//	}
//};
//class WebFactory           //网站工厂类，用于存放共享的WebSite对象
//{
//private:
//	vector<WebSite*>websites;
//public:
//	WebSite* GetWeb()
//	{
//		vector<WebSite*>::iterator p = websites.begin();
//		return *p;
//	}
//	WebFactory()      //工厂类的默认构造函数是加入共享网站对象
//	{ 
//		websites.push_back(new ConcreteWebSite("测试"));
//	}
//};
//int mian()
//{
//	WebFactory* f = new WebFactory();
//	WebSite* ws = f->GetWeb();
//	ws->Use();
//
//	WebSite* ws2 = f->GetWeb();
//	ws2->Use();
//
//	WebSite* ws3 = new UnShareWebSite("测试");
//	ws3->Use();
//	return 0;
//}
//
////第二十三、解释器模式
////通常当一个语言需要解释执行，并且你可以将该语言中的句子表示成为一个抽象的语法树时，可以使用解释器模式
//class Context;
//class AbstractExpression
//{
//public:
//	virtual void Interpret(Context* context) = 0;
//};
//class Expression :public AbstractExpression
//{
//public:
//	virtual void Interpret(Context* context)
//	{
//		cout << "终端解释器" << endl;
//	}
//};
//class NonterminalExpression :public AbstractExpression
//{
//public:
//	virtual void Interpret(Context* context)
//	{
//		cout << "非终端解释器" << endl;
//	}
//};
//class Context
//{
//public:
//	string input;
//	string output;
//};
//int main()
//{
//	Context* context = new Context();
//	vector<AbstractExpression*>express;
//	express.push_back(new Expression());
//	express.push_back(new NonterminalExpression());
//	express.push_back(new NonterminalExpression());
//
//	vector<AbstractExpression*>::iterator p = express.begin();
//	while (p != express.end())
//	{
//		(*p)->Interpret(context);
//		p++;
//	}
//	return 0;
//}
//
////第二十四、访问者模式
//class Man;
//class Woman;
//class Action    //行为
//{
//public:
//	virtual void GetManConclusion(Man* concreteElementA) = 0;
//	virtual void GetWomanConclusion(Woman* concreteElementB) = 0;
//};
//class Success :public Action      //成功
//{
//public:
//	virtual void GetManConclusion(Man* concreteElementA)
//	{
//		cout << "男人成功时，背后有个伟大的女人" << endl;
//	}
//	virtual void GetWomanConclusion(Woman* concreteElementB)
//	{
//		cout << "女人成功时，背后有个伟大的男人" << endl;
//	}
//};
//class Failure :public Action      //失败
//{
//public:
//	virtual void GetManConclusion(Man* concreteElementA)
//	{
//		cout << "男人失败时，背后有个伟大的女人" << endl;
//	}
//	virtual void GetWomanConclusion(Woman* concreteElementB)
//	{
//		cout << "女人失败时，背后有个伟大的男人" << endl;
//	}
//};
//class Person  //抽象人类
//{
//public:
//	virtual void Accept(Action* visitor) = 0;
//};
//class Man :public Person
//{
//public:
//	virtual void Accept(Action* visitor)
//	{
//		visitor->GetManConclusion(this);
//	}
//};
//class Woman :public Person
//{
//public:
//	virtual void Accept(Action* visitor)
//	{
//		visitor->GetWomanConclusion(this);
//	}
//};
//class ObjectStructure     //对象结构类
//{
//private:
//	vector<Person*>m_personList;
//public:
//	void Add(Person* p)
//	{
//		m_personList.push_back(p);
//	}
//	void Display(Action* a)
//	{
//		vector<Person*>::iterator p = m_personList.begin();
//		while (p != m_personList.end())
//		{
//			(*p)->Accept(a);
//			p++;
//		}
//	}
//};
//int main()
//{
//	ObjectStructure* os = new ObjectStructure();
//	os->Add(new Man());
//	os->Add(new Woman());
//
//	Success* success = new Success();
//	os->Display(success);
//
//	Failure* f = new Failure();
//	os->Display(f);
//	return 0;
//}