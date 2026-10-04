
undefined4 __thiscall FUN_005ed28f(int param_1,LPVOID param_2,DWORD param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined4 uVar3;
  
  DVar1 = param_3;
  BVar2 = ReadFile(*(HANDLE *)(param_1 + 0x14),param_2,param_3,&param_3,(LPOVERLAPPED)0x0);
  if ((BVar2 == 0) || (param_3 != DVar1)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

