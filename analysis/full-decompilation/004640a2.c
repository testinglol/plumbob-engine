
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004640a2(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  undefined4 uVar4;
  float10 fVar5;
  undefined8 uVar6;
  undefined *puVar7;
  undefined1 local_44 [32];
  undefined1 local_24 [16];
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  FUN_00437961(&local_14,param_3);
  if (DAT_006e5280 != 0) {
    FUN_00635858(local_44,&DAT_006c08e4,(int)*(short *)(param_1 + 0xf0));
    uVar1 = *(undefined4 *)(param_3 + 0x10);
    uVar2 = *(undefined4 *)(param_3 + 0x14);
    uVar6 = CONCAT44(2,local_44);
    uVar4 = FUN_00492d2c(local_44,2);
    FUN_004373ae(local_24,uVar1,uVar2,uVar4,uVar6);
    FUN_004b467f();
    FUN_00422698();
  }
  if (DAT_006e5282 == 0) goto LAB_004641f2;
  FUN_00457da4();
  sVar3 = FUN_004561a0();
  if (sVar3 == 0) goto LAB_004641f2;
  if ((DAT_006e5282 < 1) ||
     ((uint)(*(int *)(param_1 + 0x1b0) - *(int *)(param_1 + 0x1ac) >> 2) < (uint)(int)DAT_006e5282))
  {
LAB_004641a6:
    puVar7 = &DAT_006c0ff8;
LAB_004641ab:
    FUN_006358b0(local_44,puVar7);
  }
  else {
    fVar5 = (float10)FUN_00463da6();
    if (fVar5 == (float10)_DAT_00667470) {
      puVar7 = &DAT_006c0fb0;
      goto LAB_004641ab;
    }
    if (fVar5 == (float10)DAT_00667474) {
      puVar7 = &DAT_006c0fec;
      goto LAB_004641ab;
    }
    if (fVar5 == (float10)DAT_00667478) goto LAB_004641a6;
    FUN_00635858(local_44,&DAT_006c4718,(double)fVar5);
  }
  uVar1 = *(undefined4 *)(param_3 + 0x10);
  uVar2 = *(undefined4 *)(param_3 + 0x14);
  uVar6 = CONCAT44(2,local_44);
  uVar4 = FUN_00492d2c(local_44,2);
  FUN_004373ae(local_24,uVar1,uVar2,uVar4,uVar6);
  FUN_004b467f();
  FUN_00422698();
LAB_004641f2:
  *param_2 = local_14;
  param_2[1] = uStack_10;
  param_2[2] = uStack_c;
  param_2[3] = uStack_8;
  return;
}

