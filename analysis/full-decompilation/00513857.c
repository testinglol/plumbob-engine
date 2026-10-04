
uint FUN_00513857(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  __ftol();
  uVar1 = __ftol();
  uVar2 = __ftol();
  uVar3 = __ftol();
  return uVar3 & 0xff | (uint)CONCAT11(uVar1,uVar2) << 8;
}

