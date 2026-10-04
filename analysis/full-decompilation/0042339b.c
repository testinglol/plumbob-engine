
void __thiscall FUN_0042339b(int param_1,int param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar7 = *(int *)(param_1 + 400);
  if (*(int *)(param_1 + 400) == 0) {
    iVar7 = param_1;
  }
  iVar3 = *(int *)(param_2 + 400);
  if (*(int *)(param_2 + 400) == 0) {
    iVar3 = param_2;
  }
  param_2 = iVar3;
  if (iVar7 != param_2) {
    do {
      piVar1 = (int *)(param_1 + 0x18c);
      param_1 = *(int *)(param_1 + 0x18c);
    } while (param_1 != 0);
    *piVar1 = param_2;
    iVar3 = *(int *)(iVar7 + 0xf4);
    iVar4 = *(int *)(iVar7 + 0xf8);
    FUN_00422055(*(undefined4 *)(iVar7 + 0x1a0),*(undefined4 *)(iVar7 + 0x1a4));
    sVar2 = *(short *)(iVar7 + 0x4c);
    if (param_2 != 0) {
      iVar6 = param_2;
      do {
        *(int *)(iVar6 + 400) = iVar7;
        *(short *)(iVar6 + 0x4c) = sVar2;
        iVar5 = (*(int *)(iVar6 + 0xf8) - iVar4) + local_14 >> 4;
        *(int *)(iVar6 + 0x1a0) = iVar5;
        *(int *)(iVar6 + 0x194) = iVar5;
        iVar5 = (*(int *)(iVar6 + 0xf4) - iVar3) + local_18 >> 4;
        *(int *)(iVar6 + 0x1a4) = iVar5;
        *(int *)(iVar6 + 0x198) = iVar5;
        FUN_004236d0(-(int)sVar2,(int *)(iVar6 + 0x194),(int *)(iVar6 + 0x198));
        iVar6 = *(int *)(iVar6 + 0x18c);
      } while (iVar6 != 0);
    }
    *(int *)(param_2 + 400) = iVar7;
  }
  return;
}

