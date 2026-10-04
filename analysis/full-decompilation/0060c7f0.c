
undefined4 FUN_0060c7f0(void)

{
  undefined4 uVar1;
  
  if ((code *)(&PTR_LAB_006d9e10)[DAT_006ff434 * 5] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0060c803. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(&PTR_LAB_006d9e10)[DAT_006ff434 * 5])();
    return uVar1;
  }
  return 0;
}

