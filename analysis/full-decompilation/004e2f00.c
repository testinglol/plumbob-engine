
void FUN_004e2f00(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int local_8;
  
  puVar2 = (undefined4 *)FUN_00425e2d();
  for (piVar5 = (int *)*puVar2; piVar5 != (int *)puVar2[1]; piVar5 = piVar5 + 1) {
    if (((~(byte)(*(uint *)(*piVar5 + 0x138) >> 3) & 1) != 0) &&
       (piVar3 = (int *)(*piVar5 + 0x10c), *piVar3 != 0)) {
      local_8 = *piVar3;
      FUN_0042eab4(&local_8);
    }
  }
  FUN_004e609e();
  uVar4 = FUN_004ed868();
  if (((uVar4 < 2) && ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0)) && (DAT_006f255c == '\0')) {
    DAT_006f255c = '\x01';
    for (piVar5 = (int *)*puVar2; piVar5 != (int *)puVar2[1]; piVar5 = piVar5 + 1) {
      iVar1 = *piVar5;
      if (((*(int *)(iVar1 + 0x10c) != 0) && (0 < *(int *)(iVar1 + 0x110))) &&
         (*(int *)(iVar1 + 0x110) < 10)) {
        *(uint *)(iVar1 + 0x138) = *(uint *)(iVar1 + 0x138) & 0xfffffff7;
        local_8 = *(int *)(*piVar5 + 0x10c);
        FUN_0042eab4(&local_8);
      }
    }
  }
  return;
}

