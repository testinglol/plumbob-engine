
void __fastcall FUN_004172e7(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined **local_128 [3];
  undefined1 local_11c [260];
  undefined4 *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 == '\0') {
    uVar7 = 0xffffffcf;
  }
  else {
    uVar7 = 0;
  }
  FUN_004659fc(uVar7);
  iVar3 = FUN_00401f6f();
  if (iVar3 == 0) {
    FUN_00416f95();
    FUN_00416e18(param_1);
    local_8 = FUN_00401f6f();
    FUN_00416fac();
    local_c = 0;
    do {
      if (local_c == 0) {
        puVar6 = (undefined4 *)param_1[6];
      }
      else {
        puVar6 = (undefined4 *)param_1[7];
      }
      local_10 = 0;
      for (puVar4 = puVar6; local_18 = puVar6, puVar4 != (undefined4 *)0x0;
          puVar4 = (undefined4 *)*puVar4) {
        local_10 = local_10 + 1;
      }
      for (; puVar4 = puVar6, iVar3 = local_10, 0 < local_10; local_10 = local_10 + -1) {
        for (; 1 < iVar3; iVar3 = iVar3 + -1) {
          if (puVar4 == (undefined4 *)0x0) goto LAB_00417387;
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) {
LAB_00417387:
          local_14 = 0;
        }
        else {
          local_14 = puVar4[1];
        }
        iVar3 = 0;
        puVar4 = puVar6;
        if (puVar6 != (undefined4 *)0x0) {
LAB_00417394:
          if (local_14 != puVar4[1]) goto code_r0x00417399;
          for (puVar4 = (undefined4 *)puVar4[2]; puVar4 != (undefined4 *)0x0;
              puVar4 = (undefined4 *)*puVar4) {
            iVar3 = iVar3 + 1;
          }
        }
joined_r0x004173a4:
        for (; 0 < iVar3; iVar3 = iVar3 + -1) {
          puVar4 = (undefined4 *)0x0;
          iVar5 = iVar3;
          puVar1 = puVar6;
          for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
            if (local_14 == puVar1[1]) {
              puVar4 = (undefined4 *)puVar1[2];
              for (; (puVar4 != (undefined4 *)0x0 && (1 < iVar5)); iVar5 = iVar5 + -1) {
                puVar4 = (undefined4 *)*puVar4;
              }
            }
            puVar6 = local_18;
          }
          if ((puVar4[2] == -1) && ((**(code **)(*param_1 + 0x7c))(puVar4[4]), local_8 == 0)) {
            local_8 = FUN_00401f6f();
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < 1);
    if ((local_8 == 0) && (local_8 = FUN_004131cb(), local_8 != 0)) {
      FUN_0046f824(local_11c,0,0x104);
      local_128[0] = &PTR_FUN_006664e8;
      FUN_004131e6(local_128);
      local_8 = FUN_00413154();
      if (local_8 == 0) {
        local_8 = FUN_004130d2(local_128,1);
      }
    }
    FUN_004659fc(local_8);
  }
  return;
code_r0x00417399:
  puVar4 = (undefined4 *)*puVar4;
  if (puVar4 == (undefined4 *)0x0) goto joined_r0x004173a4;
  goto LAB_00417394;
}

