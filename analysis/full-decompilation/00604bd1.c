
bool __thiscall FUN_00604bd1(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  cVar1 = (**(code **)(*param_1 + 8))(param_2);
  bVar3 = false;
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(*param_1 + 0x14))();
    bVar3 = param_2 == iVar2;
  }
  return bVar3;
}

