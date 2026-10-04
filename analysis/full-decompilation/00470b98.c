
void __fastcall FUN_00470b98(int param_1)

{
  char *_Str;
  short sVar1;
  int *piVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  short sVar10;
  undefined4 *puVar11;
  short *psVar12;
  int local_c;
  int local_8;
  
  local_8 = 0;
  iVar5 = 4;
  do {
    piVar2 = (int *)(*(int *)(param_1 + 0x6c) + local_8);
    puVar11 = (undefined4 *)*piVar2;
    if (puVar11 != (undefined4 *)piVar2[1]) {
      do {
        if ((char *)*puVar11 == (char *)0x0) {
          sVar3 = 0;
        }
        else {
          sVar3 = _strlen((char *)*puVar11);
        }
        if ((char *)puVar11[1] == (char *)0x0) {
          sVar4 = 0;
        }
        else {
          sVar4 = _strlen((char *)puVar11[1]);
        }
        iVar5 = iVar5 + sVar3 + 4 + sVar4;
        puVar11 = puVar11 + 3;
      } while (puVar11 != *(undefined4 **)(local_8 + 4 + *(int *)(param_1 + 0x6c)));
    }
    local_8 = local_8 + 0xc;
  } while (local_8 < 0xf0);
  iVar5 = FUN_0041ffd9(iVar5);
  if (iVar5 == 0) {
    FUN_00633a1e();
  }
  else {
    puVar6 = (undefined2 *)FUN_00420048(iVar5);
    sVar10 = 0;
    local_8 = 0;
    *puVar6 = 0xfffd;
    do {
      sVar1 = FUN_0046fc11(local_8);
      sVar10 = sVar10 + sVar1;
      local_8 = local_8 + 1;
    } while (local_8 < 0x14);
    sVar1 = 0;
    puVar6[1] = sVar10;
    psVar12 = puVar6 + 2;
    local_c = 0;
    do {
      puVar7 = (undefined4 *)(*(int *)(param_1 + 0x6c) + local_c);
      puVar11 = (undefined4 *)*puVar7;
      if (puVar11 != (undefined4 *)puVar7[1]) {
        do {
          *psVar12 = sVar1 + 1;
          puVar8 = (undefined1 *)*puVar11;
          if (puVar8 == (undefined1 *)0x0) {
            puVar8 = &DAT_006de560;
          }
          FUN_006358b0((char *)((int)psVar12 + 1),puVar8);
          sVar3 = _strlen((char *)((int)psVar12 + 1));
          _Str = (char *)((int)psVar12 + sVar3 + 2);
          puVar8 = (undefined1 *)puVar11[1];
          if (puVar8 == (undefined1 *)0x0) {
            puVar8 = &DAT_006de560;
          }
          FUN_006358b0(_Str,puVar8);
          sVar3 = _strlen(_Str);
          psVar12 = (short *)(_Str + sVar3 + 1);
          puVar11 = puVar11 + 3;
        } while (puVar11 != *(undefined4 **)(local_c + 4 + *(int *)(param_1 + 0x6c)));
      }
      local_c = local_c + 0xc;
      sVar1 = sVar1 + 1;
    } while (local_c < 0xf0);
    FUN_0042004f(iVar5);
    if ((*(int *)(param_1 + 0x58) == 0) || (*(int *)(param_1 + 0x58) == 0x435354)) {
      *(undefined4 *)(param_1 + 0x58) = 0x53545223;
    }
    (**(code **)(**(int **)(param_1 + 4) + 0x74))
              (iVar5,*(undefined4 *)(param_1 + 0x58),
               CONCAT22((short)((uint)(param_1 + 8) >> 0x10),*(undefined2 *)(param_1 + 0x54)),
               param_1 + 8,1);
    iVar9 = FUN_00401f6f();
    if (iVar9 == 0) {
      (**(code **)(**(int **)(param_1 + 4) + 0x7c))(iVar5);
      iVar9 = FUN_00401f6f();
      if (iVar9 == 0) {
        FUN_00465a06(iVar5);
        FUN_00401f6f();
      }
    }
  }
  return;
}

