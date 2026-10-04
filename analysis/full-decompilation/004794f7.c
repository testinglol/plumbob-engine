
void __thiscall FUN_004794f7(int param_1,char *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  undefined1 uVar6;
  uint uVar5;
  int local_c;
  int local_8;
  
  local_8 = (int)*param_2;
  param_2 = (char *)(int)param_2[1];
  local_c = param_1;
  FUN_0047bd91(&local_8,&param_2,-*(int *)(param_1 + 0x84) & 3,0x40);
  iVar2 = (int)param_2;
  iVar1 = *(int *)(param_1 + 0x84);
  if (iVar1 == 1) {
    uVar5 = param_3 << 0x18;
    param_3 = (int)param_3 >> 8;
  }
  else if (iVar1 == 2) {
    uVar5 = (int)param_3 >> 0x10;
    param_3 = param_3 << 0x10;
  }
  else {
    uVar5 = param_3;
    if (iVar1 != 3) goto LAB_00479564;
    uVar5 = (int)param_3 >> 0x18;
    param_3 = param_3 << 8;
  }
  uVar5 = uVar5 | param_3;
LAB_00479564:
  param_3 = uVar5;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8);
  iVar1 = (int)param_2;
  *(uint *)(*piVar3 + iVar2 * 4) = uVar5;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8 + -1);
  iVar2 = (int)param_2;
  uVar6 = (undefined1)(uVar5 >> 8);
  *(undefined1 *)(*piVar3 + 2 + iVar1 * 4) = uVar6;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8 + -1);
  uVar4 = (undefined1)uVar5;
  *(undefined1 *)(*piVar3 + 3 + iVar2 * 4) = uVar4;
  iVar1 = (int)param_2 + -1;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8);
  *(undefined1 *)(*piVar3 + iVar1 * 4) = uVar6;
  iVar1 = (int)param_2 + -1;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8);
  iVar2 = (int)param_2;
  *(undefined1 *)(*piVar3 + 3 + iVar1 * 4) = param_3._2_1_;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8 + 1);
  iVar1 = (int)param_2;
  *(undefined1 *)(*piVar3 + 1 + iVar2 * 4) = param_3._2_1_;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8 + 1);
  *(undefined1 *)(*piVar3 + iVar1 * 4) = param_3._3_1_;
  iVar1 = (int)param_2 + 1;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8);
  *(undefined1 *)(*piVar3 + 1 + iVar1 * 4) = uVar4;
  iVar1 = (int)param_2 + 1;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8);
  *(undefined1 *)(*piVar3 + 2 + iVar1 * 4) = param_3._3_1_;
  iVar1 = (int)param_2 + -1;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8 + 1);
  *(undefined1 *)(*piVar3 + iVar1 * 4) = param_3._2_1_;
  iVar1 = (int)param_2 + 1;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8 + -1);
  *(undefined1 *)(*piVar3 + 2 + iVar1 * 4) = uVar4;
  iVar1 = (int)param_2 + 1;
  piVar3 = (int *)FUN_0047c7b7(&local_c,local_8 + 1);
  *(undefined1 *)(*piVar3 + 1 + iVar1 * 4) = param_3._3_1_;
  iVar1 = (int)param_2 + -1;
  piVar3 = (int *)FUN_0047c7b7(&param_3,local_8 + -1);
  *(undefined1 *)(*piVar3 + 3 + iVar1 * 4) = uVar6;
  return;
}

