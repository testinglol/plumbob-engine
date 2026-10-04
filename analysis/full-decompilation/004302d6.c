
void __thiscall FUN_004302d6(int *param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if ((param_4 == *param_1) || (param_3 != 0)) {
LAB_0043031d:
    iVar2 = FUN_00430988(param_5);
    *(int *)(param_4 + 8) = iVar2;
    iVar3 = *param_1;
    if (param_4 != iVar3) {
      if (param_4 == *(int *)(iVar3 + 8)) {
        *(int *)(iVar3 + 8) = iVar2;
      }
      goto LAB_0043033f;
    }
    *(int *)(iVar3 + 4) = iVar2;
    iVar3 = *param_1;
  }
  else {
    iVar3 = *param_5;
    iVar2 = *(int *)(param_4 + 0x10);
    bVar4 = SBORROW4(iVar3,iVar2);
    iVar1 = iVar3 - iVar2;
    if (iVar3 == iVar2) {
      bVar4 = SBORROW4(param_5[1],*(int *)(param_4 + 0x14));
      iVar1 = param_5[1] - *(int *)(param_4 + 0x14);
    }
    if (bVar4 != iVar1 < 0) goto LAB_0043031d;
    iVar2 = FUN_00430988(param_5);
    *(int *)(param_4 + 0xc) = iVar2;
    iVar3 = *param_1;
    if (param_4 != *(int *)(iVar3 + 0xc)) goto LAB_0043033f;
  }
  *(int *)(iVar3 + 0xc) = iVar2;
LAB_0043033f:
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(int *)(iVar2 + 4) = param_4;
  FUN_00430367(iVar2,*param_1 + 4);
  param_1[1] = param_1[1] + 1;
  *param_2 = iVar2;
  return;
}

