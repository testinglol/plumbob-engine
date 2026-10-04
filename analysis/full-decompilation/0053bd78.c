
undefined4 __thiscall FUN_0053bd78(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_00435221(param_3,0);
  if (iVar2 < 4) {
    bVar1 = (char)iVar2 * '\x02';
    *(uint *)(param_1 + 4) =
         ~(3 << (bVar1 & 0x1f)) & *(uint *)(param_1 + 4) | param_2 << (bVar1 & 0x1f);
  }
  return param_3;
}

