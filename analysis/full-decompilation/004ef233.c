
void FUN_004ef233(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffe58;
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  *(undefined1 *)(extraout_ECX + 0xf5) = 1;
  uVar2 = (**(code **)(*DAT_006fe8bc + 0x34))();
  *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
  DAT_006f29f7 = 0;
  cVar1 = FUN_005d6516(s_skip_intro_006ca850,0,1);
  if (cVar1 != '\0') {
    DAT_006f29f7 = 1;
  }
  DAT_006f29f8 = 0;
  cVar1 = FUN_005d6516(s_software_intro_006ca840,0,1);
  if (cVar1 != '\0') {
    DAT_006f29f8 = 1;
  }
  cVar1 = FUN_005d6516(s_no_thread_init_006ca830,0,1);
  if (cVar1 != '\0') {
    DAT_006c9f58 = 0;
  }
  cVar1 = FUN_005d6516(s_dynamic_draw_006ca820,0,1);
  if (cVar1 != '\0') {
    *(undefined1 *)(DAT_006e486c + 0x5c) = 1;
  }
  DAT_006c2973 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004ee998();
  FUN_004ef301();
  return;
}

