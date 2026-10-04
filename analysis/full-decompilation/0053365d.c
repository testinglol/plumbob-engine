
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0053365d(int param_1)

{
  int iVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  char *pcVar5;
  size_t sVar6;
  int iVar7;
  size_t sVar8;
  int iVar9;
  undefined4 uVar12;
  double dVar10;
  undefined8 uVar11;
  undefined4 uVar13;
  char local_120 [272];
  undefined4 local_10;
  undefined8 local_c;
  
  if ((*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4)) / 0x28 != 0) {
    if ((int)*(uint *)(param_1 + 0xe0) < 0) {
      *(undefined4 *)(param_1 + 0xe0) = 0;
    }
    else if ((uint)((*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4)) / 0x28) <=
             *(uint *)(param_1 + 0xe0)) {
      *(int *)(param_1 + 0xe0) = (*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4)) / 0x28 + -1;
    }
    if (((*(int *)(param_1 + 0x11c) < *(int *)(param_1 + 0x124)) &&
        (*(int *)(param_1 + 0x120) < *(int *)(param_1 + 0x128))) && (*(int *)(param_1 + 0xe4) != 0))
    {
      cVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
      if (cVar3 != '\0') {
        uVar13 = 0;
        local_c = (double)CONCAT44(**(undefined4 **)(param_1 + 0x5c),(undefined4)local_c);
        uVar4 = FUN_004df599();
        uVar12 = 0;
        (**(code **)(local_c._4_4_ + 0x40))();
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1,uVar12,uVar4,uVar13);
      }
      local_10 = (**(code **)(**(int **)(param_1 + 0xe4) + 0x1c))();
      iVar1 = **(int **)(param_1 + 0xe4);
      uVar4 = FUN_005340bf(*(undefined4 *)(param_1 + 0xe0));
      (**(code **)(iVar1 + 0x20))(uVar4);
      pcVar5 = (char *)FUN_004096c2();
      if (pcVar5 != (char *)0x0) {
        sVar6 = _strlen(pcVar5);
        local_c = (double)CONCAT44(sVar6,(undefined4)local_c);
        (**(code **)(**(int **)(param_1 + 0xe4) + 0x78))
                  (*(undefined4 *)(param_1 + 0x5c),
                   *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x11c),
                   *(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x20),pcVar5,sVar6,0,0,0);
      }
      (**(code **)(**(int **)(param_1 + 0xe4) + 0x20))(DAT_006f2a44);
      fVar2 = *(float *)(param_1 + 0x140) * _DAT_00667364;
      local_c = (double)fVar2;
      if (fVar2 <= (float)_DAT_00667888) {
        pcVar5 = s_us_per_tick___f_006cce08;
        dVar10 = local_c;
      }
      else {
        pcVar5 = s_ms_per_tick___f_006cce18;
        dVar10 = (double)(fVar2 * _DAT_00666a24);
      }
      FUN_00635858(local_120,pcVar5,dVar10);
      iVar1 = **(int **)(param_1 + 0xe4);
      uVar11 = 0;
      uVar4 = 0;
      sVar6 = _strlen(local_120);
      pcVar5 = local_120;
      iVar7 = *(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x20);
      iVar9 = **(int **)(param_1 + 0xe4);
      sVar8 = _strlen(local_120);
      iVar9 = (**(code **)(iVar9 + 0x68))(local_120,sVar8,iVar7,pcVar5,sVar6,uVar4,uVar11);
      (**(code **)(iVar1 + 0x78))
                (*(undefined4 *)(param_1 + 0x5c),
                 (*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x1c)) - iVar9);
      (**(code **)(**(int **)(param_1 + 0xe4) + 0x20))(local_10);
    }
  }
  return;
}

