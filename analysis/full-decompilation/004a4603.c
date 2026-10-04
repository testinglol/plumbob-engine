
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004a4603(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_006321f0(*(int *)(param_1 + 0x10));
  }
  pvVar1 = operator_new(*(int *)(param_1 + 0x4c) << 3);
  fVar4 = (float)_DAT_00667280;
  *(void **)(param_1 + 0x10) = pvVar1;
  if (fVar4 <= *(float *)(param_1 + 0x48)) {
    FUN_0049e977(*(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x60));
    FUN_0049e977(*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 100));
    iVar5 = param_1 + 0x20;
    uVar6 = 1;
    uVar2 = FUN_0049cdb0(*(float *)(param_1 + 0x48) - (float)_DAT_00667280);
    fVar4 = *(float *)(param_1 + 0x48) - (float)_DAT_00667280;
  }
  else {
    FUN_0049e977(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x58));
    FUN_0049e977(*(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x5c));
    iVar5 = param_1 + 0x20;
    uVar6 = 1;
    uVar2 = FUN_0049cdb0(*(undefined4 *)(param_1 + 0x48));
    fVar4 = *(float *)(param_1 + 0x48);
  }
  uVar3 = FUN_0049cdb0(fVar4);
  FUN_004a5412(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x4c),uVar3,uVar2,iVar5,
               uVar6);
  return;
}

