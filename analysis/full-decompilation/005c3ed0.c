
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * __thiscall FUN_005c3ed0(int param_1,void *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float *local_f4;
  char *local_f0;
  char *local_ec;
  float *local_e8;
  float *local_e0;
  char *local_dc;
  float *local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  int local_c8;
  float local_c4 [2];
  float local_bc;
  float local_b8;
  float local_b4 [21];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  _vector_constructor_iterator_(local_b4 + 1,0x10,4,(_func_void_ptr_void_ptr *)&LAB_005c3c10);
  FUN_005c47c0(param_1);
  FUN_005c47c0(param_1 + 0x10);
  FUN_005c47c0(param_1 + 0x20);
  FUN_005c47c0(param_1 + 0x30);
  FUN_005c42c0(local_b4 + 0x11);
  iVar7 = 8;
  local_e0 = local_b4 + 1;
  local_d8 = &local_b8;
  local_e8 = local_b4;
  local_c8 = 4 - (int)(local_b4 + 1);
  local_ec = (char *)0x0;
  while( true ) {
    local_e8 = (float *)((int)local_e8 + 0x10);
    local_dc = local_ec + 1;
    pcVar5 = local_ec;
    if ((int)local_dc < 4) {
      local_f4 = (float *)(iVar7 + -8);
      iVar6 = iVar7 + 8;
      pfVar8 = (float *)((int)&stack0xfffffefc * 5 + (local_c8 + (int)local_ec * 5) * 4 + 0x1a4);
      local_f0 = local_dc;
      do {
        if (ABS(*(float *)((int)local_b4 + (int)local_f4 + (int)local_ec * 4 + 4U)) < ABS(*pfVar8))
        {
          pcVar5 = local_f0;
          local_f4 = (float *)iVar6;
        }
        iVar6 = iVar6 + 0x10;
        local_f0 = local_f0 + 1;
        pfVar8 = pfVar8 + 4;
      } while (iVar6 < 0x40);
    }
    FUN_005c47c0(local_b4 + (int)pcVar5 * 4U + 1);
    pfVar8 = (float *)((int)local_d8 + iVar7);
    FUN_005c47c0(pfVar8);
    FUN_005c47c0(local_10);
    FUN_005c47c0(local_b4 + (int)pcVar5 * 4U + 0x11);
    pfVar1 = (float *)((int)local_b4 + iVar7 + 0x3cU);
    FUN_005c47c0(pfVar1);
    FUN_005c47c0(local_20);
    if (*local_e0 == (float)_DAT_006669e8) break;
    fVar2 = _DAT_00666748 / *local_e0;
    local_f4 = local_b4;
    local_f0 = (char *)0x0;
    *pfVar1 = fVar2 * *pfVar1;
    *(float *)((int)local_b4 + iVar7 + 0x40U) = fVar2 * *(float *)((int)local_b4 + iVar7 + 0x40U);
    *(float *)((int)local_b4 + iVar7 + 0x44U) = fVar2 * *(float *)((int)local_b4 + iVar7 + 0x44U);
    *(float *)((int)local_b4 + iVar7 + 0x48U) = fVar2 * *(float *)((int)local_b4 + iVar7 + 0x48U);
    *pfVar8 = fVar2 * *pfVar8;
    iVar6 = 8;
    *(float *)((int)local_b4 + iVar7) = fVar2 * *(float *)((int)local_b4 + iVar7);
    *(float *)((int)local_b4 + iVar7 + 4U) = fVar2 * *(float *)((int)local_b4 + iVar7 + 4U);
    *local_e8 = fVar2 * *local_e8;
    pfVar8 = local_b4 + (int)local_ec + 1;
    do {
      local_f4 = (float *)((int)local_f4 + 0x10);
      if (local_f0 != local_ec) {
        local_c4[0] = *(float *)((int)local_b4 + iVar7 + 0x48U) * *pfVar8;
        local_d4 = *(float *)((int)local_b4 + iVar7 + 0x44U) * *pfVar8;
        local_d0 = *(float *)((int)local_b4 + iVar7 + 0x40U) * *pfVar8;
        local_cc = *pfVar8 * *(float *)((int)local_b4 + iVar7 + 0x3cU);
        FUN_005c4790(&local_cc,&local_d0,&local_d4,local_c4);
        *(float *)((int)local_b4 + iVar6 + 0x3cU) =
             *(float *)((int)local_b4 + iVar6 + 0x3cU) - local_30;
        *(float *)((int)local_b4 + iVar6 + 0x40U) =
             *(float *)((int)local_b4 + iVar6 + 0x40U) - local_2c;
        *(float *)((int)local_b4 + iVar6 + 0x44U) =
             *(float *)((int)local_b4 + iVar6 + 0x44U) - local_28;
        *(float *)((int)local_b4 + iVar6 + 0x48U) =
             *(float *)((int)local_b4 + iVar6 + 0x48U) - local_24;
        local_bc = *(float *)((int)local_b4 + iVar7) * *pfVar8;
        fVar4 = *(float *)((int)local_b4 + iVar7 + 4U) * *pfVar8;
        local_b8 = fVar4;
        fVar2 = *local_e8;
        fVar3 = *pfVar8;
        local_b4[0] = fVar2 * fVar3;
        *(float *)((int)local_d8 + iVar6) =
             *(float *)((int)local_d8 + iVar6) - *pfVar8 * *(float *)((int)local_d8 + iVar7);
        *(float *)((int)local_b4 + iVar6) = *(float *)((int)local_b4 + iVar6) - local_bc;
        *(float *)((int)local_b4 + iVar6 + 4U) = *(float *)((int)local_b4 + iVar6 + 4U) - fVar4;
        *local_f4 = *local_f4 - fVar2 * fVar3;
      }
      iVar6 = iVar6 + 0x10;
      local_f0 = local_f0 + 1;
      pfVar8 = pfVar8 + 4;
    } while (iVar6 < 0x48);
    local_ec = local_dc;
    iVar7 = iVar7 + 0x10;
    local_e0 = local_e0 + 5;
    if (0x47 < iVar7) {
      _vector_constructor_iterator_(param_2,0x10,4,(_func_void_ptr_void_ptr *)&LAB_005c3c10);
      FUN_005c47c0(local_b4 + 0x11);
      FUN_005c47c0(local_60);
      FUN_005c47c0(local_50);
      FUN_005c47c0(local_40);
      return param_2;
    }
  }
  local_dc = s_U3DAlgebra3_error_006d2c58;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_dc,&DAT_006b79f0);
}

