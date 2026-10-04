
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051ceee(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  uint uVar5;
  int iVar6;
  undefined4 local_54;
  uint local_50;
  
  FUN_00634c24();
  uVar5 = *(uint *)(*(int *)(unaff_EBP + 8) + 0xc);
  *(uint *)(unaff_EBP + -0x1c) = uVar5;
  local_50 = 0x51cf0e;
  uVar3 = FUN_004cfb43();
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
  if ((uVar5 & 0x20080000) != 0) {
    uVar5 = 0;
    if (extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2 != 0) {
      do {
        if (*(int *)(extraout_ECX[0x3c] + uVar5 * 4) != 0) {
          local_50 = 0x51cf4a;
          (**(code **)(**(int **)(extraout_ECX[0x3c] + uVar5 * 4) + 0x98))();
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)(extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2));
    }
    if (extraout_ECX[199] != 0) {
      *(undefined4 **)(unaff_EBP + -0x28) = &local_54;
      local_54 = 0;
      local_50 = 0;
      FUN_005e4fb5(0);
      extraout_ECX[199] = 0;
    }
    local_50 = 0x51cf89;
    uVar3 = FUN_004e9902();
    *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
    if (8 < *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -0x18) = 8;
    }
    iVar6 = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    if (0 < *(int *)(unaff_EBP + -0x18)) {
      do {
        local_54 = 0x51cfab;
        local_50 = iVar6;
        uVar3 = FUN_004e9918();
        *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
        local_50 = 0x51cfb7;
        FUN_005c1719();
        local_50 = unaff_EBP + -0x20;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        local_54 = *(undefined4 *)(unaff_EBP + -0x14);
        cVar2 = FUN_004e93e4();
        if (cVar2 != '\0') {
          iVar6 = iVar6 * 4;
          if (*(int *)(iVar6 + extraout_ECX[0x3c]) != 0) {
            piVar1 = *(int **)(iVar6 + extraout_ECX[0x3c]);
            local_50 = 3;
            local_54 = 4;
            iVar4 = *piVar1;
            *(int **)(unaff_EBP + -0x28) = piVar1;
            uVar3 = FUN_004096c2();
            (**(code **)(iVar4 + 0x19c))(uVar3);
            FUN_005b8680();
            *(undefined1 *)(unaff_EBP + -4) = 1;
            iVar4 = FUN_004eabb1(*(undefined4 *)(unaff_EBP + -0x14));
            if (iVar4 < 3) {
              FUN_005d48d9();
              *(undefined1 *)(unaff_EBP + -4) = 2;
              FUN_004eb157(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x40);
              uVar3 = FUN_004096c2();
              FUN_005d4bbf(uVar3);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_005b8770();
            }
            else {
              FUN_004e9d82(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x34);
            }
            uVar3 = FUN_004096c2();
            FUN_005d4956(uVar3);
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_005dd9c8(unaff_EBP + -0x4c);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_005b8770();
            (**(code **)(**(int **)(iVar6 + extraout_ECX[0x3c]) + 0x94))();
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_005b8770();
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        local_50 = 0x51d0c1;
        FUN_005a5e09();
        iVar6 = *(int *)(unaff_EBP + -0x24) + 1;
        *(int *)(unaff_EBP + -0x24) = iVar6;
      } while (iVar6 < *(int *)(unaff_EBP + -0x18));
    }
  }
  uVar5 = *(uint *)(unaff_EBP + -0x1c) & 9;
  if (uVar5 != 0) {
    local_50 = 0x51d0e3;
    (**(code **)(*extraout_ECX + 0x168))();
  }
  if (*(int *)(unaff_EBP + -0x10) == -1) {
    local_50 = 0;
    local_54 = 0x51d0f2;
    FUN_0051d3e7();
  }
  else {
    if (extraout_ECX[0x3f] == 0) {
      local_50 = 1;
      local_54 = 0x51d10f;
      FUN_0051d3e7();
    }
    if ((extraout_ECX[0x47] != 0) && (extraout_ECX[0x3f] == 3)) {
      local_50 = *(undefined4 *)(unaff_EBP + -0x10);
      local_54 = 0x51d138;
      cVar2 = FUN_004cffcb();
      local_50 = 1;
      if (cVar2 == '\0') {
        local_54 = 0x51d174;
        cVar2 = (**(code **)(*(int *)extraout_ECX[0x47] + 0x8c))();
        if (cVar2 == '\x01') {
          local_50 = 0x51d186;
          (**(code **)(*(int *)extraout_ECX[0x47] + 0x98))();
          local_50 = 0x51d194;
          (**(code **)(*(int *)extraout_ECX[0x44] + 0x94))();
          goto LAB_0051d194;
        }
      }
      else {
        local_54 = 0x51d14c;
        cVar2 = (**(code **)(*(int *)extraout_ECX[0x47] + 0x8c))();
        if (cVar2 == '\0') {
          local_50 = 0x51d15e;
          (**(code **)(*(int *)extraout_ECX[0x47] + 0x94))();
          local_50 = 0x51d16c;
          (**(code **)(*(int *)extraout_ECX[0x44] + 0x98))();
LAB_0051d194:
          local_50 = 0x51d1a2;
          (**(code **)(*(int *)extraout_ECX[0x45] + 0x98))();
          local_50 = 0x51d1b0;
          (**(code **)(*(int *)extraout_ECX[0x46] + 0x98))();
          local_50 = 0x51d1be;
          (**(code **)(*(int *)extraout_ECX[0x49] + 0x98))();
        }
      }
    }
  }
  while (uVar5 != 0) {
    iVar6 = 0;
    do {
      local_50 = 0x51d1d2;
      FUN_00513bb6();
      local_50 = 0x51d1e0;
      FUN_00513bb6();
      iVar6 = iVar6 + 4;
    } while (iVar6 < 0x20);
    local_50 = 0x51d1f6;
    uVar5 = FUN_00473417();
  }
  if (extraout_ECX[0x3a] != -1) {
    if ((*(uint *)(unaff_EBP + -0x1c) & 0x10008) != 0) {
      if (extraout_ECX[0x3f] == 2) {
        iVar6 = 0;
        do {
          local_50 = *(undefined4 *)(unaff_EBP + -0x10);
          local_54 = 0x51d22c;
          FUN_00521647();
          iVar6 = iVar6 + 4;
        } while (iVar6 < 0x14);
      }
      local_50 = *(undefined4 *)(unaff_EBP + -0x10);
      local_54 = 0x51d23c;
      iVar6 = FUN_004e9744();
      if ((iVar6 == 0) || (1 < *(short *)(iVar6 + 0x60e))) {
        local_50 = 0x51d269;
        (**(code **)(*(int *)extraout_ECX[0x71] + 0x98))();
      }
      else {
        local_50 = 0x51d259;
        (**(code **)(*(int *)extraout_ECX[0x71] + 0x94))();
      }
    }
    if ((*(uint *)(unaff_EBP + -0x1c) & 0x6008008) != 0) {
      iVar6 = extraout_ECX[0x3f];
      if (iVar6 == 5) {
        do {
          local_50 = 0x51d28d;
          FUN_0051d7c8();
          local_50 = 0x51d294;
          iVar6 = FUN_00473417();
        } while (iVar6 != 0);
      }
      else if (iVar6 == 6) {
        local_50 = 0x51d2a6;
        FUN_0051e1a1();
      }
      else if (iVar6 == 7) {
        local_50 = 0x51d2b4;
        FUN_0051e3b5();
      }
    }
    if ((*(byte *)(unaff_EBP + -0x1c) & 8) == 0) goto LAB_0051d2c4;
  }
  local_50 = *(undefined4 *)(unaff_EBP + -0x10);
  local_54 = 0x51d2c4;
  FUN_0051c61b();
LAB_0051d2c4:
  uVar5 = 0;
  if (extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2 != 0) {
    do {
      if (*(int *)(uVar5 * 4 + extraout_ECX[0x3c]) != 0) {
        local_54 = 0x51d2ee;
        local_50 = uVar5;
        local_50 = FUN_004e9918();
        *(uint *)(unaff_EBP + 8) = local_50;
        if (local_50 != -1) {
          local_54 = 0x51d2fd;
          iVar6 = FUN_004ea7e2();
          if (iVar6 != 0) {
            local_50 = *(undefined4 *)(unaff_EBP + 8);
            local_54 = 0x51d30a;
            iVar6 = FUN_004ea7e2();
            if (_DAT_0066c7b8 <= *(float *)(iVar6 + 0xc)) {
              if (*(float *)(iVar6 + 0xc) <= _DAT_00667360) {
                local_50 = 0;
              }
              else {
                local_50 = 1;
              }
            }
            else {
              local_50 = 2;
            }
            local_54 = 0x51d33e;
            FUN_005e4320();
          }
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)(extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

