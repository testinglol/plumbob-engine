
/* WARNING: Removing unreachable block (ram,0x005ef306) */

char __fastcall FUN_005eee43(int *param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  FARPROC pFVar5;
  int iVar6;
  size_t sVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined1 local_38 [12];
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined1 local_24 [8];
  undefined4 *local_1c;
  HMODULE local_18;
  undefined4 local_14;
  undefined4 local_10;
  char local_c;
  undefined4 local_8;
  
  FUN_00436a50(4);
  param_1[0x1b] = (int)DAT_006fe8bc;
  puVar4 = (undefined4 *)(**(code **)(param_1[0x12] + 0xc))(local_24);
  local_14 = *puVar4;
  local_10 = puVar4[1];
  *(char *)(param_1 + 0x1f) = '\x01' - (DAT_006ff0b4 != '\0');
  local_18 = LoadLibraryA(s_ddraw_dll_006d2d98);
  if (local_18 == (HMODULE)0x0) {
    local_c = '\0';
  }
  else {
    pFVar5 = GetProcAddress(local_18,s_DirectDrawCreate_006d2d84);
    param_1[0xb2] = (int)pFVar5;
    pFVar5 = GetProcAddress(local_18,s_DirectDrawEnumerateA_006d2d6c);
    param_1[0xb3] = (int)pFVar5;
    if ((param_1[0xb2] == 0) || (param_1[0xb3] == 0)) {
      local_c = '\0';
    }
    else {
      cVar3 = FUN_005ef7b8();
      if (cVar3 == '\0') {
        local_c = '\0';
      }
      else {
        cVar3 = FUN_005ef955();
        if (cVar3 == '\0') {
          local_c = '\0';
        }
        else {
          FUN_005ef3fc(*(int *)param_1[0x30] + 8);
          if (DAT_006ff094 != 0xffffffff) {
            for (local_1c = *(undefined4 **)param_1[0x30]; local_28 = (undefined4 *)param_1[0x30],
                local_1c != local_28; local_1c = (undefined4 *)*local_1c) {
              iVar6 = _memcmp(&DAT_006ff094,local_1c + 2,0x10);
              if (iVar6 == 0) {
                FUN_005ef3fc(local_1c + 2);
                break;
              }
              sVar7 = _strlen((char *)&DAT_006ff094);
              iVar6 = FUN_004558e0(&DAT_006ff094,0,sVar7);
              if (iVar6 != -1) {
                FUN_005ef3fc(local_1c + 2);
                break;
              }
              local_2c = local_1c;
            }
          }
          cVar3 = FUN_005efac6();
          if (cVar3 == '\0') {
            local_c = '\0';
          }
          else {
            piVar8 = (int *)(**(code **)(param_1[0x12] + 0x10))(local_38);
            param_1[0x23] = *piVar8;
            param_1[0x24] = piVar8[1];
            param_1[0x25] = piVar8[2];
            iVar6 = DAT_006ff090;
            param_1[0x20] = param_1[0x18] - param_1[0x16];
            param_1[0x21] = param_1[0x19] - param_1[0x17];
            param_1[0x22] = iVar6;
            if (((char)param_1[0x1f] == '\0') &&
               ((((iVar6 = _memcmp(param_1 + 0x31,&DAT_006f2a14,0x10), iVar6 != 0 ||
                  (param_1[0x25] != DAT_006ff090)) || ((uint)param_1[0x23] < DAT_006ff088)) ||
                ((uint)param_1[0x24] < DAT_006ff08c)))) {
              *(undefined1 *)(param_1 + 0x1f) = 1;
            }
            uVar2 = DAT_006ff08c;
            uVar1 = DAT_006ff088;
            param_1[0x16] = 0;
            param_1[0x17] = 0;
            param_1[0x18] = uVar1;
            param_1[0x19] = uVar2;
            if (((char)param_1[0x1f] != '\0') &&
               (cVar3 = FUN_005ef53d(&DAT_006ff088,param_1 + 0x31), cVar3 == '\0')) {
              *(undefined1 *)(param_1 + 0x1f) = 0;
            }
            cVar3 = (**(code **)(param_1[0x6a] + 0xc))();
            if (cVar3 == '\0') {
              local_c = '\0';
            }
            else {
              (**(code **)(param_1[0x12] + 0x1c))();
              local_8 = 0;
              FUN_005efa04(0);
              if ((char)param_1[0x1f] != '\0') {
                *(undefined1 *)(param_1 + 0x1f) = 0;
                (**(code **)(*param_1 + 0x28))(1);
              }
              local_c = (**(code **)(param_1[0x3f] + 0xe8))
                                  (DAT_006ff088,DAT_006ff08c,DAT_006d9318,local_14,local_10,local_8,
                                   DAT_006d931c,DAT_006d9320,DAT_006ff0b5);
              if (local_c == '\0') {
                local_c = '\0';
              }
              else {
                if ((*(char *)((int)param_1 + 0x171) == '\0') && ((char)param_1[99] == '\0')) {
                  uVar9 = (**(code **)(param_1[0x3f] + 0xf8))();
                  (**(code **)(param_1[0x6a] + 0x1b4))(uVar9);
                }
                FUN_005dea7b();
                if ((char)param_1[0x1f] == '\0') {
                  (**(code **)(param_1[0x6a] + 0x1a8))();
                }
                param_1[0x13] = 0;
                (**(code **)(*DAT_006fe8bc + 0x18))();
                FUN_005d96f2();
              }
            }
          }
        }
      }
    }
  }
  return local_c;
}

