
/* Library Function - Single Match
    __mbsncoll
   
   Library: Visual Studio 2003 Release */

int __cdecl __mbsncoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (_MaxCount == 0) {
    return 0;
  }
  uVar1 = FUN_0063c58c(_Str1,_MaxCount);
  uVar2 = FUN_0063c58c(_Str2,_MaxCount);
  iVar3 = FUN_00646501(DAT_00705344,0,_Str1,uVar1,_Str2,uVar2,DAT_00705124);
  if (iVar3 == 0) {
    return 0x7fffffff;
  }
  return iVar3 + -2;
}

