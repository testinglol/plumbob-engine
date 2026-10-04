
void __thiscall FUN_005c2748(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(*param_1 + 4);
  iVar4 = *param_1;
  while (iVar3 = iVar1, iVar3 != 0) {
    cVar2 = FUN_005c1797(param_3);
    if (cVar2 == '\0') {
      iVar1 = *(int *)(iVar3 + 8);
      iVar4 = iVar3;
    }
    else {
      iVar1 = *(int *)(iVar3 + 0xc);
    }
  }
  *param_2 = iVar4;
  return;
}

