
void __fastcall FUN_00535494(int param_1)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  char *_Str;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int local_10;
  char *local_8;
  
  if (*(int *)(param_1 + 0xdc) == 0) {
    *(int *)(param_1 + 0xdc) = DAT_006f2aa4;
  }
  piVar1 = *(int **)(param_1 + 0xdc);
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar1 + 0x58))();
    iVar8 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c);
    if (0 < iVar8) {
      *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xd8) / iVar3;
      iVar4 = iVar8 - *(int *)(param_1 + 0xd4);
      *(int *)(param_1 + 0xe8) = iVar4;
      iVar4 = (**(code **)(*piVar1 + 100))
                        (*(int *)(param_1 + 0x4c),
                         *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c),iVar4);
      if (*(int *)(param_1 + 0xf0) < iVar4) {
        pcVar2 = *(char **)(param_1 + 0x4c);
        local_10 = 0;
        local_8 = pcVar2;
        if (0 < *(int *)(param_1 + 0xf0)) {
          do {
            uVar9 = *(undefined4 *)(param_1 + 0xe8);
            iVar4 = *piVar1;
            sVar5 = _strlen(local_8);
            iVar4 = (**(code **)(iVar4 + 0x60))(local_8,sVar5,uVar9);
            local_8 = local_8 + iVar4;
            local_10 = local_10 + 1;
          } while (local_10 < *(int *)(param_1 + 0xf0));
        }
        *(int *)(param_1 + 0xfc) = iVar8;
        *(int *)(param_1 + 0xec) = (int)local_8 - (int)pcVar2;
        iVar4 = *(int *)(param_1 + 0x50);
        iVar7 = *(int *)(param_1 + 0x4c);
        *(undefined4 *)(param_1 + 0x100) = 0;
        for (_Str = pcVar2 + ((int)local_8 - (int)pcVar2); _Str < pcVar2 + (iVar4 - iVar7);
            _Str = _Str + iVar6) {
          uVar9 = *(undefined4 *)(param_1 + 0xfc);
          iVar6 = *piVar1;
          sVar5 = _strlen(_Str);
          iVar6 = (**(code **)(iVar6 + 0x60))(_Str,sVar5,uVar9);
          *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
        }
        iVar7 = *(int *)(param_1 + 0x80);
        iVar4 = *(int *)(param_1 + 0x7c);
        iVar3 = *(int *)(param_1 + 0x100) * iVar3 + *(int *)(param_1 + 0xd8);
      }
      else {
        iVar3 = *(int *)(param_1 + 0xd8);
        *(undefined4 *)(param_1 + 0xfc) = 0;
        *(undefined4 *)(param_1 + 0x100) = 0;
        *(int *)(param_1 + 0xf0) = iVar4;
        iVar4 = *(int *)(param_1 + 0x7c);
        *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c);
        iVar7 = *(int *)(param_1 + 0x80);
      }
      FUN_005dda18(iVar4,iVar7,iVar4 + iVar8,iVar3 + iVar7);
    }
  }
  return;
}

