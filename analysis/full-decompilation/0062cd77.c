
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0062cd77(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar3 = *(int *)(param_1 + 0x24a8) >> 3;
  if (*(char *)(param_1 + 0x4a0e) == '\0') {
    uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
    uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
            (-((byte)*(int *)(param_1 + 0x24a8) & 7) - 9 & 0x1f) & _DAT_0067bb78;
    iVar3 = *(int *)(param_1 + 0x24a8) + 9;
    *(int *)(param_1 + 0x24a8) = iVar3;
    *(uint *)(param_1 + 0x34cc) = uVar1;
    iVar3 = iVar3 >> 3;
    if (*(int *)(param_1 + 0x4a40) == 1) {
      uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
      uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
              (-((byte)*(int *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68;
      iVar3 = *(int *)(param_1 + 0x24a8) + 5;
    }
    else {
      uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
      uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
              (-((byte)*(int *)(param_1 + 0x24a8) & 7) - 3 & 0x1f) & _DAT_0067bb60;
      iVar3 = *(int *)(param_1 + 0x24a8) + 3;
    }
    local_8 = 0;
    *(int *)(param_1 + 0x24a8) = iVar3;
    *(uint *)(param_1 + 0x34d0) = uVar1;
    if (0 < *(int *)(param_1 + 0x4a40)) {
      puVar4 = (uint *)(param_1 + 0x34d8);
      do {
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
        puVar4[-1] = uVar1;
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
        *puVar4 = uVar1;
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
        puVar4[1] = uVar1;
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
        local_8 = local_8 + 1;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
        puVar4[2] = uVar1;
        puVar4 = puVar4 + 0x28;
      } while ((int)local_8 < *(int *)(param_1 + 0x4a40));
    }
    local_c = 0x3528;
    do {
      uVar1 = 0;
      local_8 = 0;
      if (0 < *(int *)(param_1 + 0x4a40)) {
        local_10 = 0;
        puVar4 = (uint *)(param_1 + -0x40 + local_c);
        do {
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 0xc & 0x1f) & _DAT_0067bb84;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 0xc;
          puVar4[-1] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 9 & 0x1f) & _DAT_0067bb78;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 9;
          *puVar4 = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 8 & 0x1f) & _DAT_0067bb74;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 8;
          puVar4[1] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 4 & 0x1f) & _DAT_0067bb64;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 4;
          puVar4[2] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
          puVar4[3] = uVar1;
          iVar3 = *(int *)(param_1 + 0x24a8) >> 3;
          if (uVar1 == 0) {
            uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
            puVar4[6] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
            puVar4[7] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
            puVar4[8] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 4 & 0x1f) & _DAT_0067bb64
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 4;
            puVar4[0xc] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 3 & 0x1f) & _DAT_0067bb60
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 3;
            puVar4[0xd] = uVar1;
            puVar4[4] = 0;
          }
          else {
            uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 2 & 0x1f) & _DAT_0067bb5c
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 2;
            puVar4[4] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
            puVar4[5] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
            puVar4[6] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
            puVar4[7] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 3 & 0x1f) & _DAT_0067bb60
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 3;
            puVar4[9] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 3 & 0x1f) & _DAT_0067bb60
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 3;
            puVar4[10] = uVar1;
            uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                    ) >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 3 & 0x1f) & _DAT_0067bb60
            ;
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 3;
            puVar4[0xb] = uVar1;
            if (puVar4[4] == 0) {
              return 0;
            }
            if ((puVar4[4] == 2) && (puVar4[5] == 0)) {
              puVar4[0xc] = 8;
            }
            else {
              puVar4[0xc] = 7;
            }
            puVar4[0xd] = 0x14 - puVar4[0xc];
          }
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
          puVar4[0xe] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
          puVar4[0xf] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar2 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
          uVar1 = local_8 + 1;
          *(uint *)(local_c + local_10 + param_1) = uVar2;
          local_10 = local_10 + 0xa0;
          puVar4 = puVar4 + 0x28;
          local_8 = uVar1;
        } while ((int)uVar1 < *(int *)(param_1 + 0x4a40));
      }
      local_c = local_c + 0x48;
    } while (local_c < 0x35b8);
  }
  else {
    uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
    uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
            (-((byte)*(int *)(param_1 + 0x24a8) & 7) - 8 & 0x1f) & _DAT_0067bb74;
    iVar3 = *(int *)(param_1 + 0x24a8) + 8;
    *(int *)(param_1 + 0x24a8) = iVar3;
    *(uint *)(param_1 + 0x34cc) = uVar1;
    iVar3 = iVar3 >> 3;
    if (*(int *)(param_1 + 0x4a40) == 1) {
      uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
      uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
              (-((byte)*(int *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
      iVar3 = *(int *)(param_1 + 0x24a8) + 1;
    }
    else {
      uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
      uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
              (-((byte)*(int *)(param_1 + 0x24a8) & 7) - 2 & 0x1f) & _DAT_0067bb5c;
      iVar3 = *(int *)(param_1 + 0x24a8) + 2;
    }
    local_8 = 0;
    *(int *)(param_1 + 0x24a8) = iVar3;
    *(uint *)(param_1 + 0x34d0) = uVar1;
    if (0 < *(int *)(param_1 + 0x4a40)) {
      puVar4 = (uint *)(param_1 + 0x34e8);
      do {
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 0xc & 0x1f) & _DAT_0067bb84;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 0xc;
        puVar4[-1] = uVar1;
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 9 & 0x1f) & _DAT_0067bb78;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 9;
        *puVar4 = uVar1;
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 8 & 0x1f) & _DAT_0067bb74;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 8;
        puVar4[1] = uVar1;
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 9 & 0x1f) & _DAT_0067bb78;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 9;
        puVar4[2] = uVar1;
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
        puVar4[3] = uVar1;
        iVar3 = *(int *)(param_1 + 0x24a8) >> 3;
        if (uVar1 == 0) {
          uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
          puVar4[6] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
          puVar4[7] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
          puVar4[8] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 4 & 0x1f) & _DAT_0067bb64;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 4;
          puVar4[0xc] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 3 & 0x1f) & _DAT_0067bb60;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 3;
          puVar4[0xd] = uVar1;
          puVar4[4] = 0;
        }
        else {
          uVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 2 & 0x1f) & _DAT_0067bb5c;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 2;
          puVar4[4] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
          puVar4[5] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
          puVar4[6] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 5 & 0x1f) & _DAT_0067bb68;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 5;
          puVar4[7] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 3 & 0x1f) & _DAT_0067bb60;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 3;
          puVar4[9] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 3 & 0x1f) & _DAT_0067bb60;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 3;
          puVar4[10] = uVar1;
          uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)
                  >> (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 3 & 0x1f) & _DAT_0067bb60;
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 3;
          puVar4[0xb] = uVar1;
          if (puVar4[4] == 0) {
            return 0;
          }
          if ((puVar4[4] == 2) && (puVar4[5] == 0)) {
            puVar4[0xc] = 8;
          }
          else {
            puVar4[0xc] = 7;
            puVar4[0xd] = 0xd;
          }
        }
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar1 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
        puVar4[0xf] = uVar1;
        uVar1 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        uVar2 = (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >>
                (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 1 & 0x1f) & _DAT_0067bb58;
        uVar1 = local_8 + 1;
        *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 1;
        puVar4[0x10] = uVar2;
        puVar4 = puVar4 + 0x28;
        local_8 = uVar1;
      } while ((int)uVar1 < *(int *)(param_1 + 0x4a40));
    }
  }
  return CONCAT31((int3)(uVar1 >> 8),1);
}

