
void __fastcall FUN_00567c7e(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0x326;
  *(undefined4 *)(param_1 + 0x1cc) = 0x326;
  *(undefined4 *)(param_1 + 0x22c) = 0x326;
  *(undefined4 *)(param_1 + 0x288) = 0x25e;
  *(undefined4 *)(param_1 + 0x2e8) = 0x25e;
  *(undefined4 *)(param_1 + 0x348) = 0x25e;
  *(undefined4 *)(param_1 + 0x290) = 0x330;
  *(undefined4 *)(param_1 + 0x2f0) = 0x330;
  *(undefined4 *)(param_1 + 0x350) = 0x330;
  *(undefined4 *)(param_1 + 0x168) = 0x1d4;
  *(undefined4 *)(param_1 + 0x1c8) = 0x1e0;
  *(undefined4 *)(param_1 + 0x228) = 0x1ec;
  *(undefined4 *)(param_1 + 0x170) = 0x1a4;
  *(undefined4 *)(param_1 + 0x1d0) = 0x1b8;
  *(undefined4 *)(param_1 + 0x230) = 0x1db;
  *(undefined4 *)(param_1 + 0x28c) = 0x21a;
  *(undefined4 *)(param_1 + 0x2ec) = 0x23e;
  *(undefined4 *)(param_1 + 0x34c) = 0x262;
  *(undefined4 *)(param_1 + 0x178) = 0xd;
  *(undefined4 *)(param_1 + 0x1d8) = 0xb;
  *(undefined4 *)(param_1 + 0x238) = 10;
  *(undefined4 *)(param_1 + 0x298) = 8;
  *(undefined4 *)(param_1 + 0x2f8) = 7;
  *(undefined4 *)(param_1 + 0x358) = 5;
  *(undefined4 *)(param_1 + 0x17c) = 0x28;
  *(undefined4 *)(param_1 + 0x1dc) = 0x23;
  *(undefined4 *)(param_1 + 0x23c) = 0x1e;
  *(undefined4 *)(param_1 + 0x29c) = 0x14;
  *(undefined4 *)(param_1 + 0x2fc) = 0xc;
  *(undefined4 *)(param_1 + 0x35c) = 10;
  puVar9 = (undefined4 *)(param_1 + 0x130);
  do {
    piVar1 = puVar9 + -4;
    FUN_004071be(*piVar1,puVar9[-3]);
    piVar2 = puVar9 + -1;
    FUN_004071be(*piVar2,*puVar9);
    FUN_004071be(puVar9[2],puVar9[3]);
    FUN_004071be(puVar9[5],puVar9[6]);
    FUN_004071be(puVar9[8],puVar9[9]);
    FUN_004071be(puVar9[0xb],puVar9[0xc]);
    iVar3 = puVar9[0xf];
    iVar4 = puVar9[0xe];
    local_8 = 0;
    iVar6 = ((2 < local_c) - 1 & 2) - 1;
    puVar9[0x11] = iVar6;
    iVar5 = puVar9[0x12];
    local_20 = iVar5;
    if (0 < iVar5) {
      local_18 = iVar5 << 3;
      local_1c = iVar5 * 0x18;
      local_14 = 0;
      local_10 = 0;
      do {
        local_24 = 0;
        FUN_0040555d(&local_24);
        local_24 = iVar3;
        FUN_0040555d(&local_24);
        local_24 = iVar4;
        FUN_0040555d(&local_24);
        iVar7 = _rand();
        local_24 = (iVar7 % 0x12) / 2;
        if (iVar6 < 1) {
          piVar8 = (int *)(*piVar1 + local_8 * 4);
          *piVar8 = *piVar8 + local_1c;
          piVar8 = (int *)(*piVar2 + local_8 * 4);
          *piVar8 = *piVar8 + local_14 + local_20 * -8;
        }
        else {
          piVar8 = (int *)(*piVar1 + local_8 * 4);
          *piVar8 = *piVar8 + local_10 + iVar5 * -0x18;
          piVar8 = (int *)(local_8 * 4 + *piVar2);
          *piVar8 = *piVar8 + local_18;
        }
        FUN_0040555d(&local_24);
        local_24 = 0;
        FUN_0040555d(&local_24);
        local_24 = 0;
        FUN_0040555d(&local_24);
        local_8 = local_8 + 1;
        local_10 = local_10 + 0x18;
        local_14 = local_14 + 8;
        local_18 = local_18 + -8;
        local_1c = local_1c + -0x18;
      } while (local_8 < local_20);
    }
    local_c = local_c + 1;
    puVar9 = puVar9 + 0x18;
  } while (local_c < 6);
  return;
}

