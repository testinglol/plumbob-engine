
void __thiscall FUN_00602d57(int *param_1,int *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *param_1;
  iVar2 = *(int *)(iVar5 + 4);
  iVar4 = iVar5;
  if (iVar2 != 0) {
    iVar3 = iVar2;
    do {
      if (*param_3 < *(uint *)(iVar3 + 0x10)) {
        iVar1 = *(int *)(iVar3 + 8);
        iVar4 = iVar3;
      }
      else {
        iVar1 = *(int *)(iVar3 + 0xc);
      }
      iVar3 = iVar1;
    } while (iVar1 != 0);
  }
  if (iVar2 != 0) {
    do {
      if (*(uint *)(iVar2 + 0x10) < *param_3) {
        iVar3 = *(int *)(iVar2 + 0xc);
      }
      else {
        iVar3 = *(int *)(iVar2 + 8);
        iVar5 = iVar2;
      }
      iVar2 = iVar3;
    } while (iVar3 != 0);
  }
  *param_2 = iVar5;
  param_2[1] = iVar4;
  return;
}

