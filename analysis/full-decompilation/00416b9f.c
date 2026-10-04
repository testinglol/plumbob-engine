
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00416b9f(int param_1)

{
  ushort uVar1;
  undefined4 local_11c;
  undefined4 local_8;
  
  FUN_004169e6(1);
  uVar1 = 0;
  if (param_1 == 0) {
    if ((local_8 == 0) || (uVar1 = *(ushort *)(local_8 + 4), uVar1 == 0xffff)) {
      uVar1 = ~-(ushort)(local_11c != 0) & _DAT_00666758;
    }
  }
  else if (param_1 == 1) {
    if ((local_8 == 0) || (*(short *)(local_8 + 4) == -1)) {
      uVar1 = ~-(ushort)(local_11c != 0) & _DAT_0066675a;
    }
    else {
      uVar1 = *(short *)(local_8 + 4) + 1;
    }
  }
  else if (param_1 == 2) {
    if ((local_8 == 0) || (*(short *)(local_8 + 4) == -1)) {
      uVar1 = ~-(ushort)(local_11c != 0) & _DAT_0066675c;
    }
    else {
      uVar1 = *(short *)(local_8 + 4) + 2;
    }
  }
  FUN_00416a38();
  return uVar1;
}

