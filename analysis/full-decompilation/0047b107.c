
uint __fastcall FUN_0047b107(byte *param_1)

{
  uint in_EAX;
  int iVar1;
  
  if ((*param_1 & 0x10) != 0) {
    iVar1 = FUN_00435221(0x10,0);
    in_EAX = (uint)*(ushort *)(param_1 + iVar1 * 2 + 8);
    if ((((in_EAX != 2) && (in_EAX != 0xc)) && (in_EAX != 0xd)) && (in_EAX != 0xe))
    goto LAB_0047b15c;
  }
  if ((*param_1 & 0x20) != 0) {
    iVar1 = FUN_00435221(0x20,0);
    in_EAX = (uint)*(ushort *)(param_1 + iVar1 * 2 + 8);
    if (((in_EAX != 2) && (in_EAX != 0xc)) && ((in_EAX != 0xd && (in_EAX != 0xe)))) {
LAB_0047b15c:
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}

