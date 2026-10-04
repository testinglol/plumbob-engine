
undefined4 __thiscall FUN_0045697c(int param_1,short param_2)

{
  short *psVar1;
  
  psVar1 = *(short **)(param_1 + 0x244);
  while( true ) {
    if (psVar1 == *(short **)(param_1 + 0x248)) {
      return 0;
    }
    if (*psVar1 == param_2) break;
    psVar1 = psVar1 + 4;
  }
  return *(undefined4 *)(psVar1 + 2);
}

