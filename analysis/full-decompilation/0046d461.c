
char __fastcall FUN_0046d461(int param_1)

{
  short sVar1;
  short sVar2;
  char cVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined4 local_2c [8];
  undefined4 local_c;
  char local_6;
  char local_5;
  
  uVar5 = FUN_0046f546();
  FUN_0046f54c(*(undefined4 *)(param_1 + 0xac));
  local_5 = FUN_0046d66f();
  uVar6 = FUN_0046f546();
  *(undefined4 *)(param_1 + 0xac) = uVar6;
  FUN_0046f54c(uVar5);
  local_c = 0;
  local_6 = '\0';
  bVar12 = local_5 == '\0';
  if (!bVar12) {
    *(short *)(param_1 + 0x1c) = *(short *)(param_1 + 0x1c) + 2;
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
    if (0x3b < *(short *)(param_1 + 0x1c)) {
      *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 1;
      *(short *)(param_1 + 0x1c) = *(short *)(param_1 + 0x1c) + -0x3c;
      local_c = 0xdb;
      if (0x3b < *(short *)(param_1 + 0x1a)) {
        *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + 1;
        *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + -0x3c;
        local_6 = '\x01';
        if (0x17 < *(short *)(param_1 + 0x10)) {
          *(short *)(param_1 + 0x48) = *(short *)(param_1 + 0x48) + 1;
          *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 1;
          *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + -0x18;
          local_c = 0xdc;
          FUN_00442668();
          FUN_00429f5e();
          iVar9 = 4;
          puVar7 = (undefined4 *)(param_1 + 0x104);
          do {
            iVar9 = iVar9 + -1;
            puVar10 = puVar7 + -8;
            puVar11 = puVar7;
            for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar11 = puVar11 + 1;
            }
            puVar7 = puVar7 + 8;
          } while (iVar9 != 0);
          puVar7 = (undefined4 *)(param_1 + 0x184);
          puVar10 = (undefined4 *)(param_1 + 0xe4);
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar10 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar10 = puVar10 + 1;
          }
          puVar7 = local_2c;
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          sVar1 = *(short *)(param_1 + 0x1e);
          sVar2 = *(short *)(param_1 + 0x20);
          puVar7 = local_2c;
          puVar10 = (undefined4 *)(param_1 + 0x184);
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar10 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar10 = puVar10 + 1;
          }
          iVar9 = FUN_0047365d((int)sVar2,(int)sVar1);
          if (iVar9 < *(short *)(param_1 + 0x12)) {
            *(short *)(param_1 + 0x1e) = *(short *)(param_1 + 0x1e) + 1;
            *(undefined2 *)(param_1 + 0x12) = 1;
            if (0xc < *(short *)(param_1 + 0x1e)) {
              *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + 1;
              *(undefined2 *)(param_1 + 0x1e) = 1;
            }
            uVar4 = FUN_0047365d((int)*(short *)(param_1 + 0x20),(int)*(short *)(param_1 + 0x1e));
            *(undefined2 *)(param_1 + 0x4a) = uVar4;
          }
        }
      }
    }
    bVar12 = local_5 == '\0';
  }
  cVar3 = FUN_00441311(bVar12);
  if (cVar3 != '\0') {
    *(undefined4 *)(param_1 + 0xbc) = 0;
    *(undefined4 *)(param_1 + 0xb8) = 0;
  }
  if ((short)local_c != 0) {
    FUN_0040766a(local_c,0);
  }
  if ((local_6 != '\0') &&
     (sVar1 = *(short *)(param_1 + 0x18), iVar9 = FUN_0046d641(), iVar9 != sVar1)) {
    *(short *)(param_1 + 0x18) = (short)iVar9;
    FUN_004c482f();
    FUN_0040766a(0xf8,5);
    FUN_0040766a(0xdd,0);
  }
  return local_5;
}

