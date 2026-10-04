
undefined4 __fastcall FUN_004131e6(int param_1)

{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 4) == (undefined4 *)0x0) {
    uVar1 = 0xffffffcf;
  }
  else {
    FUN_0046f8cb(**(undefined4 **)(param_1 + 4));
    uVar1 = 0;
  }
  return uVar1;
}

