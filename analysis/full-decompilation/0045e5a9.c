
void __fastcall FUN_0045e5a9(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 local_4;
  
  uVar1 = *(ushort *)(param_1 + 0x84);
  uVar2 = *(ushort *)(param_1 + 0xafc);
  if (uVar1 != uVar2) {
    iVar3 = 0;
    local_4 = 0;
    if (uVar2 < 0xfffb) {
      iVar3 = FUN_004670a4(uVar2);
    }
    if (uVar1 < 0xfffb) {
      local_4 = FUN_004670a4(uVar1);
    }
    *(ushort *)(param_1 + 0xafc) = uVar1;
    if (*(short *)(param_1 + 0x60e) < 2) {
      if (iVar3 != 0) {
        iVar3 = FUN_0046894e();
        if (iVar3 == 0) {
          FUN_004688e4(0);
        }
      }
      if (local_4 != 0) {
        FUN_004688e4(1);
      }
    }
    if (((*(uint *)(param_1 + 0x114) >> 1 & 1) != 0) || (param_1 == DAT_006f6b5c)) {
      FUN_0040766a(0xf7,0);
    }
  }
  return;
}

