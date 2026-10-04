
int __thiscall FUN_0053bd4d(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_00435221(param_2,0);
  if (iVar2 < 4) {
    bVar1 = (char)iVar2 * '\x02';
    iVar2 = (int)(3 << (bVar1 & 0x1f) & *(uint *)(param_1 + 4)) >> (bVar1 & 0x1f);
  }
  else {
    iVar2 = 3;
  }
  return iVar2;
}

