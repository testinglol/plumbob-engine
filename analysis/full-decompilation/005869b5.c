
void __fastcall FUN_005869b5(int *param_1)

{
  uint uVar1;
  
  uVar1 = __ftol();
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + (7 - uVar1 & 0xfffffff8);
  }
  if (7 < (int)uVar1) {
    uVar1 = uVar1 + (uVar1 >> 3) * -8;
  }
  (**(code **)(*param_1 + 0x11c))(uVar1);
  return;
}

