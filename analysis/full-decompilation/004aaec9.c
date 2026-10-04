
void __fastcall FUN_004aaec9(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_60;
  int local_48;
  int local_30;
  int local_10;
  int *local_c;
  char local_5;
  
  FUN_00448aa5(*(undefined4 *)(param_1 + 0x1c8),*(undefined4 *)(param_1 + 0x1cc));
  FUN_00448aa5(*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x1d8));
  FUN_00448aa5(*(undefined4 *)(param_1 + 0x1e0),*(undefined4 *)(param_1 + 0x1e4));
  piVar2 = (int *)FUN_00440389();
  piVar4 = (int *)*piVar2;
  if (piVar4 != (int *)piVar2[1]) {
    do {
      local_c = (int *)*piVar4;
      iVar5 = 0;
      if (*(short *)((int)local_c + 0x8e) == 0) {
        cVar1 = (**(code **)(*local_c + 0x28))();
        if (cVar1 != '\0') {
          FUN_0044845a(&local_c);
        }
        local_5 = '\0';
        iVar7 = (local_c[0x4d] - local_c[0x4c]) / 0x24 + -1;
        piVar6 = local_c;
        if (0 < iVar7) {
          local_10 = 0x24;
          do {
            if ((local_10 < 0x24) || ((piVar6[0x4d] - piVar6[0x4c]) / 0x24 + -1 <= iVar5)) {
              iVar3 = 0;
            }
            else {
              iVar3 = local_10 + piVar6[0x4c];
            }
            if (iVar3 == 0) {
              iVar3 = 0;
            }
            else {
              iVar3 = FUN_00407498((int)*(short *)(iVar3 + 0x10));
              piVar6 = local_c;
            }
            if ((iVar3 != 0) &&
               (((*(byte *)(*(int *)(iVar3 + 0x118) + 0xca) & 1) != 0 ||
                (*(char *)(DAT_006e486c + 0x5c) != '\0')))) {
              local_5 = '\x01';
              break;
            }
            local_10 = local_10 + 0x24;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar7);
        }
        if ((((((*(byte *)(piVar6[0x46] + 0xca) & 1) == 0) &&
              (*(char *)(DAT_006e486c + 0x5c) == '\0')) ||
             (cVar1 = FUN_004576f4(), piVar6 = local_c, cVar1 == '\0')) ||
            (FUN_0043270d(local_c), piVar6 = local_c, local_30 != 0)) &&
           ((local_5 == '\0' || (FUN_0043270d(piVar6), piVar6 = local_c, local_48 != 0)))) {
          if (((*(short *)((int)piVar6 + 0x8e) == 0) && (cVar1 = FUN_004576f4(), cVar1 != '\0')) &&
             ((FUN_0043270d(local_c), local_60 == 0 &&
              ((((local_c[0x57] == 1 && ((*(byte *)(local_c[0x46] + 0xca) & 1) == 0)) &&
                (*(char *)(DAT_006e486c + 0x5c) == '\0')) && (local_5 == '\0')))))) {
            iVar7 = DAT_006e5490 - local_c[0x56];
            iVar5 = (**(code **)(*local_c + 0x18))();
            if ((iVar5 < iVar7) && (local_c[0x55] != 0x7fffffff)) {
              FUN_004346fc(0,0);
            }
            else {
              cVar1 = FUN_00433136(local_c + 0x3f);
              if (cVar1 == '\0') goto LAB_004ab11e;
            }
          }
        }
        else {
          FUN_004346fc(1,0);
LAB_004ab11e:
          FUN_0044845a(&local_c);
        }
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != (int *)piVar2[1]);
  }
  return;
}

