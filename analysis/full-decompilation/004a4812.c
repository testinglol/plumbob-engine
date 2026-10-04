
void __fastcall FUN_004a4812(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x13];
  if (iVar1 == 0x20) {
    param_1[0x13] = 0x40;
  }
  else if (iVar1 == 0x40) {
    param_1[0x13] = 0x80;
  }
  else if (iVar1 == 0x80) {
    param_1[0x13] = 0x100;
  }
  else {
    param_1[0x13] = 0x20;
  }
                    /* WARNING: Could not recover jumptable at 0x004a4845. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xc))();
  return;
}

