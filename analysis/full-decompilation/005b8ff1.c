
char __thiscall FUN_005b8ff1(undefined4 *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  
  iVar1 = param_2;
  cVar2 = (**(code **)(*(int *)param_1[3] + 0x20))(param_2);
  if (cVar2 != '\0') {
    if (param_1[8] != 0) {
      cVar3 = FUN_005b9bbe(*param_1,&param_2);
      if (cVar3 != '\0') {
        *(int *)(param_2 + 0xc) = iVar1;
      }
    }
    param_1[4] = iVar1;
  }
  return cVar2;
}

