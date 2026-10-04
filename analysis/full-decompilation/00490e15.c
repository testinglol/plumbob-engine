
void FUN_00490e15(void)

{
  void *pvVar1;
  size_t sVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006e57cc == 0) {
    pvVar1 = operator_new(0x20);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_006e57cc = 0;
    }
    else {
      DAT_006e57cc = FUN_0047c37a(0x40);
    }
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    sVar2 = _strlen(s_terrain_scratch_006c6054);
    FUN_00401a3c(s_terrain_scratch_006c6054,s_terrain_scratch_006c6054 + sVar2);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_004316cf(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00401729();
  }
  if (DAT_006e57c0 == 0) {
    pvVar1 = operator_new(0x20);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    if (pvVar1 == (void *)0x0) {
      DAT_006e57c0 = 0;
    }
    else {
      DAT_006e57c0 = FUN_0047c8fb(0x40);
    }
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    sVar2 = _strlen(s_terrain_flags_006c6044);
    FUN_00401a3c(s_terrain_flags_006c6044,s_terrain_flags_006c6044 + sVar2);
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_004316cf(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00401729();
  }
  *(undefined4 *)(extraout_ECX + 0x3c) = 0xffffffff;
  FUN_00490cd9(extraout_ECX + 0x48,2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

