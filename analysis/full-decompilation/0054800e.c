
void __fastcall FUN_0054800e(int param_1)

{
  int iVar1;
  int iVar2;
  undefined **local_544;
  undefined4 local_540;
  undefined1 local_538 [256];
  undefined **local_438;
  undefined4 local_434;
  undefined1 local_42c [256];
  undefined **local_32c;
  undefined4 local_328;
  undefined1 local_320 [256];
  undefined **local_220;
  undefined4 local_21c;
  undefined1 local_214 [256];
  undefined **local_114;
  undefined4 local_110;
  undefined1 local_108 [256];
  int local_8;
  
  if (*(int *)(param_1 + 0x1e0) != 0) {
    local_8 = param_1;
    FUN_0046f824(local_214,0,0x100);
    local_220 = &PTR_FUN_00666524;
    FUN_0046f824(local_42c,0,0x100);
    local_438 = &PTR_FUN_00666524;
    FUN_0046f824(local_320,0,0x100);
    local_32c = &PTR_FUN_00666524;
    FUN_0046f824(local_538,0,0x100);
    local_544 = &PTR_FUN_00666524;
    FUN_0046f824(local_108,0,0x100);
    iVar1 = local_8;
    local_114 = &PTR_FUN_00666524;
    FUN_004e9744(*(undefined4 *)(local_8 + 0x11c));
    iVar2 = FUN_004580cc(0);
    if (iVar2 != 0) {
      FUN_00455edc(3,&local_220,&local_438,0);
      FUN_00455edc(2,&local_32c,&local_544,0);
      FUN_0046f847(s_headsuit__006cd71c,0xffffffff);
      FUN_0046f847(local_21c,0xffffffff);
      FUN_0046f847(s_headtex__006cd710,0xffffffff);
      FUN_0046f847(local_434,0xffffffff);
      FUN_0046f847(s_suitname__006cd704,0xffffffff);
      FUN_0046f847(local_328,0xffffffff);
      FUN_0046f847(s_texname__006cd6f8,0xffffffff);
      FUN_0046f847(local_540,0xffffffff);
      (**(code **)(**(int **)(iVar1 + 0x1e0) + 0x1a0))(local_110);
    }
  }
  return;
}

