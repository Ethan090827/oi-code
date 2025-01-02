# -*- coding: utf-8 -*-
  class Ctnr:
    def __init__(self):self.dict = dict();self.length = 0;self.it = -1;
    def push(self,*args):
      for arg in args:
        self.dict[str(self.length)]=arg; self.length+=1
    def __getitem__(self,i):
      try: return self.dict[str(i)]
      except: return None
    def __setitem__(self,i,x):
      self.dict[str(i)]=x
      inti = None
      try:
        inti = int(i)
        if (abs(inti - float(i))>0.0001): inti=None
      except: pass
      if (inti != None):
        self.length=inti+1
        for j in range(0,self.length):
          try:  self.dict[str(j)]
          except: self.dict[str(j)]=None
    def slice(self,i):
      ret = Ctnr();
      for i in range(i,self.length): ret.push(self[i])
      return ret
    def concat(self,other):
      ret = Ctnr();
      for i in range(0,self.length): ret.push(self[i])
      for i in range(0,other.length): ret.push(other[i])
      return ret
    def __str__(self):
      if (len(self.dict.keys())==self.length):
        ret = "["
        for k in range(0,self.length):
          v = self[k]
          if (isinstance(v,Ctnr)): ret += v.__str__()
          else: ret += str(v)
          ret+=","
        ret += "]"
        return ret;
      else:
        ret = "{"
        for k in self.dict.keys():
          ret += str(k)+":"
          v = self.dict[k]
          if (isinstance(v,Ctnr)): ret += v.__str__()
          else: ret += str(v)
          ret+=","
        ret += "}"
        return ret;
    def __repr__(self):
      return self.__str__()
    def __iter__(self):
      self.it = -1;
      return self
    def __next__(self):
      self.it += 1
      if (self.it >= self.length): raise StopIteration()
      return self[self.it]
  globals()['Ctnr']=Ctnr;
  class JSON:
    @staticmethod
    def stringify(x):
      return x;
  #####LIE4=Ctnr()
ZUO3=Ctnr()
YOU4=Ctnr()
JI4=Ctnr()
ZHI4=Ctnr()
for _rand1 in range(400000):
	ZUO3.push(0)
	YOU4.push(0)
	JI4.push(0)
	ZHI4.push(0)

QI2ZUO3=lambda _:0
def QI2ZUO3 (JIE2DIAN3):
	global LIE4;
	global ZUO3;
	global YOU4;
	global JI4;
	global ZHI4;
	global QI2ZUO3;
	_ans1=JIE2DIAN3*2;

	JIE2DIAN3=_ans1;
	return JIE2DIAN3

QI2YOU4=lambda _:0
def QI2YOU4 (JIE2DIAN3):
	global LIE4;
	global ZUO3;
	global YOU4;
	global JI4;
	global ZHI4;
	global QI2ZUO3;
	global QI2YOU4;
	_ans2=JIE2DIAN3*2;

	JIE2DIAN3=_ans2;
	_ans3=JIE2DIAN3+1;

	JIE2DIAN3=_ans3;
	return JIE2DIAN3

JIAN4SHU4=lambda _:0
def JIAN4SHU4 (ZUO3JIE4):
	def _rand2(YOU4JIE4):
		def _rand3(HAO4):
			nonlocal ZUO3JIE4;
			nonlocal YOU4JIE4;
			global LIE4;
			global ZUO3;
			global YOU4;
			global JI4;
			global ZHI4;
			global QI2ZUO3;
			global QI2YOU4;
			global JIAN4SHU4;

			ZUO3[HAO4-1]=ZUO3JIE4;

			YOU4[HAO4-1]=YOU4JIE4;

			if ZUO3JIE4==YOU4JIE4:

				JI4[HAO4-1]=0;

			ZHONG1=ZUO3JIE4
			_ans4=ZHONG1+YOU4JIE4;

			ZHONG1=_ans4;
			_ans5=ZHONG1/2;

			ZHONG1=_ans5;
			ZUO3ZI3=0
			_ans6=QI2ZUO3(HAO4);

			ZUO3ZI3=_ans6;
			_ans7=JIAN4SHU4(ZUO3JIE4)(ZHONG1)(ZUO3ZI3);
			_ans8=ZHONG1+1;

			ZHONG1=_ans8;
			YOU4ZI3=0
			_ans9=QI2YOU4(HAO4);

			YOU4ZI3=_ans9;
			_ans10=JIAN4SHU4(ZHONG1)(YOU4JIE4)(YOU4ZI3);
			_ans11=ZUO3

			HE2=_ans11;
			_ans12=HE2+YOU4;

			HE2=_ans12;

			JI4[HAO4-1]=和;
			return 
		return _rand3;
	return _rand2;

XIA4=lambda _:0
def XIA4 (HAO4):
	global LIE4;
	global ZUO3;
	global YOU4;
	global JI4;
	global ZHI4;
	global QI2ZUO3;
	global QI2YOU4;
	global JIAN4SHU4;
	global XIA4;

	if ZHI4[HAO4-1]==0:
		return 

	ZUO3ZI3=0
	_ans13=QI2ZUO3(HAO4);

	ZUO3ZI3=_ans13;
	YOU4ZI3=0
	_ans14=QI2YOU4(HAO4);

	YOU4ZI3=_ans14;

	if ZHI4[ZUO3ZI3-1]==0:

		ZHI4[ZUO3ZI3-1]=1;

	else:

		ZHI4[ZUO3ZI3-1]=0;


	if ZHI4[YOU4ZI3-1]==0:

		ZHI4[YOU4ZI3-1]=1;

	else:

		ZHI4[YOU4ZI3-1]=0;

	_ans15=YOU4

	ZUO3ZONG3=_ans15;
	_ans16=ZUO3ZONG3-ZUO3;

	ZUO3ZONG3=_ans16;
	_ans17=ZUO3ZONG3-JI4;

	ZUO3ZONG3=_ans17;
	_ans18=ZUO3ZONG3+1;

	ZUO3ZONG3=_ans18;

	JI4[ZUO3ZI3-1]=ZUO3ZONG3;
	_ans19=YOU4

	YOU4ZONG3=_ans19;
	_ans20=YOU4ZONG3-ZUO3;

	YOU4ZONG3=_ans20;
	_ans21=YOU4ZONG3-JI4;

	YOU4ZONG3=_ans21;
	_ans22=YOU4ZONG3+1;

	YOU4ZONG3=_ans22;

	JI4[YOU4ZI3-1]=YOU4ZONG3;

	ZHI4[HAO4-1]=0;
	return 

XIU1GAI3=lambda _:0
def XIU1GAI3 (ZUO3JIE4):
	def _rand4(YOU4JIE4):
		def _rand5(HAO4):
			nonlocal ZUO3JIE4;
			nonlocal YOU4JIE4;
			global LIE4;
			global ZUO3;
			global YOU4;
			global JI4;
			global ZHI4;
			global QI2ZUO3;
			global QI2YOU4;
			global JIAN4SHU4;
			global XIA4;
			global XIU1GAI3;
			ZUO3ZHI2=False

			if ZUO3JIE4<=ZUO3[HAO4-1]:

				ZUO3ZHI2=True;

			YOU4ZHI2=False

			if YOU4JIE4<=YOU4[HAO4-1]:

				YOU4ZHI2=True;

			ZUO3YOU4ZHI2=False
			_ans23=ZUO3ZHI2 and YOU4ZHI2;

			ZUO3YOU4ZHI2=_ans23;

			if ZUO3YOU4ZHI2==True:

				if ZHI4[HAO4-1]==0:

					ZHI4[HAO4-1]=1;

				else:

					ZHI4[HAO4-1]=0;

				_ans24=YOU4

				ZONG3=_ans24;
				_ans25=ZONG3-ZUO3;

				ZONG3=_ans25;
				_ans26=ZONG3-JI4;

				ZONG3=_ans26;
				_ans27=ZONG3+1;

				ZONG3=_ans27;

				JI4[HAO4-1]=ZONG3;

			ZAI4ZUO3ZHI2=False

			if ZUO3JIE4>YOU4[HAO4-1]:

				ZAI4ZUO3ZHI2=True;

			ZAI4YOU4ZHI2=False

			if YOU4JIE4<ZUO3[HAO4-1]:

				ZAI4YOU4ZHI2=True;

			ZAI4ZUO3YOU4ZHI2=False
			_ans28=ZAI4ZUO3ZHI2 or ZAI4YOU4ZHI2;

			ZAI4ZUO3YOU4ZHI2=_ans28;

			if ZAI4ZUO3YOU4ZHI2==True:
				return 

			_ans29=XIA4(HAO4);
			ZUO3ZI3=0
			_ans30=QI2ZUO3(HAO4);

			ZUO3ZI3=_ans30;
			_ans31=XIU1GAI3(ZUO3JIE4)(YOU4JIE4)(ZUO3ZI3);
			YOU4ZI3=0
			_ans32=QI2YOU4(HAO4);

			YOU4ZI3=_ans32;
			_ans33=XIU1GAI3(ZUO3JIE4)(YOU4JIE4)(YOU4ZI3);
			_ans34=ZUO3

			HE2=_ans34;
			_ans35=HE2+YOU4;

			HE2=_ans35;

			JI4[HAO4-1]=和;
			return 
		return _rand5;
	return _rand4;

WEN4=lambda _:0
def WEN4 (ZUO3JIE4):
	def _rand6(YOU4JIE4):
		def _rand7(HAO4):
			nonlocal ZUO3JIE4;
			nonlocal YOU4JIE4;
			global LIE4;
			global ZUO3;
			global YOU4;
			global JI4;
			global ZHI4;
			global QI2ZUO3;
			global QI2YOU4;
			global JIAN4SHU4;
			global XIA4;
			global XIU1GAI3;
			global WEN4;
			ZUO3ZHI2=False

			if ZUO3JIE4<=ZUO3[HAO4-1]:

				ZUO3ZHI2=True;

			YOU4ZHI2=False

			if YOU4JIE4<=YOU4[HAO4-1]:

				YOU4ZHI2=True;

			ZUO3YOU4ZHI2=False
			_ans36=ZUO3ZHI2 and YOU4ZHI2;

			ZUO3YOU4ZHI2=_ans36;

			if ZUO3YOU4ZHI2==True:
				return JI4

			ZAI4ZUO3ZHI2=False

			if ZUO3JIE4>YOU4[HAO4-1]:

				ZAI4ZUO3ZHI2=True;

			ZAI4YOU4ZHI2=False

			if YOU4JIE4<ZUO3[HAO4-1]:

				ZAI4YOU4ZHI2=True;

			ZAI4ZUO3YOU4ZHI2=False
			_ans37=ZAI4ZUO3ZHI2 or ZAI4YOU4ZHI2;

			ZAI4ZUO3YOU4ZHI2=_ans37;

			if ZAI4ZUO3YOU4ZHI2==True:
				return 0

			_ans38=XIA4(HAO4);
			ZUO3ZI3=0
			_ans39=QI2ZUO3(HAO4);

			ZUO3ZI3=_ans39;
			YOU4ZI3=0
			_ans40=QI2YOU4(HAO4);

			YOU4ZI3=_ans40;
			HE2=0
			_ans41=WEN4(ZUO3JIE4)(YOU4JIE4)(ZUO3ZI3);

			HE2=_ans41;
			_ans42=WEN4(ZUO3JIE4)(YOU4JIE4)(YOU4ZI3);
			_ans43=HE2+_ans42;

			HE2=_ans43;
			return HE2

		_ans44=require('fs').readFileSync("/dev/stdin");

		ZONG3JI4=_ans44;
		_ans45=(buf => buf.toString().trim())(ZONG3JI4);

		ZONG3JI4=_ans45;
		_ans46=(s => s.split(' '))(ZONG3JI4);

		ZONG3JI4=_ans46;
		_ans47=ZONG3JI4[1-1];
		_ans48=parseInt(_ans47);

		JIA3=_ans48;
		_ans49=ZONG3JI4[2-1];
		_ans50=parseInt(_ans49);

		YI3=_ans50;
		_ans51=JIAN4SHU4(1)(JIA3)(1);
		for _rand8 in range(YI3):
			_ans52=require('fs').readFileSync("/dev/stdin");

			ZONG3JI4=_ans52;
			_ans53=(buf => buf.toString().trim())(ZONG3JI4);

			ZONG3JI4=_ans53;
			_ans54=(s => s.split(' '))(ZONG3JI4);

			ZONG3JI4=_ans54;
			_ans55=ZONG3JI4[1-1];
			_ans56=parseInt(_ans55);

			XING2=_ans56;
			_ans57=ZONG3JI4[2-1];
			_ans58=parseInt(_ans57);

			ZUO3=_ans58;
			_ans59=ZONG3JI4[3-1];
			_ans60=parseInt(_ans59);

			YOU4=_ans60;

			if XING2==0:
				_ans61=XIU1GAI3(ZUO3)(YOU4)(1);

			else:
				_ans62=WEN4(ZUO3)(YOU4)(1);
				DA2=0

				DA2=_ans62;
				_ans63=DA2
				print(_ans63);


