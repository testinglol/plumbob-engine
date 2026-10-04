
void __thiscall FUN_0042f2dd(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  int *local_8;
  
  iVar1 = *param_1;
  bVar7 = true;
  iVar2 = iVar1;
  iVar4 = *(int *)(iVar1 + 4);
  while (iVar4 != 0) {
    iVar2 = *(int *)(iVar4 + 0x10);
    iVar3 = *param_3;
    bVar7 = SBORROW4(iVar3,iVar2);
    iVar5 = iVar3 - iVar2;
    if (iVar3 == iVar2) {
      bVar7 = SBORROW4(param_3[1],*(int *)(iVar4 + 0x14));
      iVar5 = param_3[1] - *(int *)(iVar4 + 0x14);
    }
    bVar7 = bVar7 != iVar5 < 0;
    iVar2 = iVar4;
    if (bVar7) {
      iVar4 = *(int *)(iVar4 + 8);
    }
    else {
      iVar4 = *(int *)(iVar4 + 0xc);
    }
  }
  local_8 = param_1;
  if (bVar7) {
    if (iVar2 == *(int *)(iVar1 + 8)) goto LAB_0042f35a;
    FUN_0042a392();
  }
  iVar1 = *(int *)(iVar2 + 0x10);
  iVar4 = *param_3;
  bVar7 = SBORROW4(iVar1,iVar4);
  iVar3 = iVar1 - iVar4;
  if (iVar1 == iVar4) {
    bVar7 = SBORROW4(*(int *)(iVar2 + 0x14),param_3[1]);
    iVar3 = *(int *)(iVar2 + 0x14) - param_3[1];
  }
  if (bVar7 == iVar3 < 0) {
    *(undefined1 *)(param_2 + 1) = 0;
    *param_2 = iVar2;
    return;
  }
LAB_0042f35a:
  piVar6 = (int *)FUN_004302d6(&local_8,0,iVar2,param_3);
  *param_2 = *piVar6;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}

