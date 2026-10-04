
undefined4 __fastcall FUN_0053f36c(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = __allshl();
  uVar1 = (uint)uVar3 & *param_1 | (uint)((ulonglong)uVar3 >> 0x20) & param_1[1];
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = CONCAT31((int3)(uVar1 >> 8),1);
  }
  return uVar2;
}

