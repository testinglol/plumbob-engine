
void __thiscall FUN_0047b747(int param_1,char *param_2,undefined1 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  cVar1 = *param_2;
  iVar6 = (int)param_2[1];
  iVar2 = *(int *)(param_1 + 0x14);
  iVar5 = cVar1 * 4;
  iVar7 = iVar6 * 4;
  iVar3 = *(int *)(*(int *)(iVar2 + 0xc) + iVar5);
  uVar4 = *(undefined4 *)(iVar3 + iVar7);
  param_2._2_2_ = (undefined2)((uint)uVar4 >> 0x10);
  param_2._0_2_ = CONCAT11(param_3,(char)uVar4);
  *(char **)(iVar3 + iVar7) = param_2;
  if (0 < cVar1) {
    iVar3 = *(int *)(*(int *)(iVar2 + 0xc) + -4 + iVar5);
    if (0 < iVar6) {
      param_2._3_1_ = (undefined1)((uint)*(undefined4 *)(iVar3 + iVar7) >> 0x18);
      param_2._0_2_ = (undefined2)*(undefined4 *)(iVar3 + iVar7);
      param_2._0_3_ = CONCAT12(param_3,param_2._0_2_);
      *(char **)(iVar3 + iVar7) = param_2;
      iVar3 = *(int *)(*(int *)(iVar2 + 0xc) + iVar5);
      param_2._1_3_ = (undefined3)((uint)*(undefined4 *)(iVar3 + -4 + iVar7) >> 8);
      param_2 = (char *)CONCAT31(param_2._1_3_,param_3);
      *(char **)(iVar3 + -4 + iVar7) = param_2;
      iVar2 = *(int *)(*(int *)(iVar2 + 0xc) + -4 + iVar5);
      param_2._0_3_ = (undefined3)*(undefined4 *)(iVar2 + -4 + iVar7);
      param_2 = (char *)CONCAT13(param_3,param_2._0_3_);
      goto LAB_0047b801;
    }
    param_2._3_1_ = (undefined1)((uint)*(undefined4 *)(iVar3 + iVar7) >> 0x18);
    param_2._0_2_ = (undefined2)*(undefined4 *)(iVar3 + iVar7);
    param_2._0_3_ = CONCAT12(param_3,param_2._0_2_);
    *(char **)(iVar3 + iVar7) = param_2;
  }
  if (iVar6 < 1) {
    return;
  }
  iVar2 = *(int *)(*(int *)(iVar2 + 0xc) + iVar5);
  param_2._1_3_ = (undefined3)((uint)*(undefined4 *)(iVar2 + -4 + iVar7) >> 8);
  param_2 = (char *)CONCAT31(param_2._1_3_,param_3);
LAB_0047b801:
  *(char **)(iVar2 + -4 + iVar7) = param_2;
  return;
}

