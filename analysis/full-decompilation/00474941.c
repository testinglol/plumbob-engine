
uint FUN_00474941(void)

{
  ushort *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  
  puVar1 = (ushort *)FUN_004750a6();
  if (*puVar1 == 0xffff) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = *puVar1 & 0x7fff;
  }
  puVar2 = (undefined2 *)FUN_004020a6(uVar3,puVar1[1]);
  if (puVar2 != (undefined2 *)0x0) {
    return CONCAT22((short)((uint)puVar2 >> 0x10),*puVar2) & 0xffff7fff;
  }
  return 0xffff;
}

