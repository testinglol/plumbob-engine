
void FUN_005b3260(undefined4 param_1)

{
  undefined4 unaff_retaddr;
  undefined4 uVar1;
  
  if (DAT_006fd050 == (code *)0x0) {
    uVar1 = 4;
    (*DAT_00703eec)(0x46,4);
    (*DAT_00703ef4)(uVar1,unaff_retaddr,param_1);
    (*DAT_00703eec)(0x46,DAT_006d2114);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005b3299. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_006fd050)();
  return;
}

