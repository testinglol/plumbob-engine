
void __fastcall FUN_0046fe83(int param_1)

{
  short sVar1;
  size_t sVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  short *psVar9;
  int local_8;
  
  iVar7 = 4;
  for (puVar8 = *(undefined4 **)(param_1 + 0x60); puVar8 != *(undefined4 **)(param_1 + 100);
      puVar8 = puVar8 + 1) {
    if ((char *)*puVar8 == (char *)0x0) {
      sVar2 = 0;
    }
    else {
      sVar2 = _strlen((char *)*puVar8);
    }
    iVar7 = iVar7 + sVar2 + 4;
  }
  iVar7 = FUN_0041ffd9(iVar7);
  sVar6 = 0;
  if (iVar7 == 0) {
    FUN_00633a1e();
  }
  else {
    puVar3 = (undefined2 *)FUN_00420048(iVar7);
    local_8 = 0;
    *puVar3 = 0xfffd;
    do {
      sVar1 = FUN_0046fbe5(local_8);
      sVar6 = sVar6 + sVar1;
      local_8 = local_8 + 1;
    } while (local_8 < 0x14);
    puVar3[1] = sVar6;
    psVar9 = puVar3 + 2;
    for (puVar8 = *(undefined4 **)(param_1 + 0x60); puVar8 != *(undefined4 **)(param_1 + 100);
        puVar8 = puVar8 + 1) {
      *psVar9 = *(char *)(param_1 + 0x5d) + 1;
      puVar4 = (undefined1 *)*puVar8;
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_006de560;
      }
      FUN_006358b0((char *)((int)psVar9 + 1),puVar4);
      sVar2 = _strlen((char *)((int)psVar9 + 1));
      *(undefined1 *)((int)psVar9 + sVar2 + 2) = 0;
      psVar9 = (short *)((int)psVar9 + sVar2 + 3);
    }
    FUN_0042004f(iVar7);
    if ((*(int *)(param_1 + 0x58) == 0) || (*(int *)(param_1 + 0x58) == 0x435354)) {
      *(undefined4 *)(param_1 + 0x58) = 0x53545223;
    }
    (**(code **)(**(int **)(param_1 + 4) + 0x74))
              (iVar7,*(undefined4 *)(param_1 + 0x58),
               CONCAT22((short)((uint)(param_1 + 8) >> 0x10),*(undefined2 *)(param_1 + 0x54)),
               param_1 + 8,1);
    iVar5 = FUN_00401f6f();
    if (iVar5 == 0) {
      (**(code **)(**(int **)(param_1 + 4) + 0x7c))(iVar7);
      iVar5 = FUN_00401f6f();
      if (iVar5 == 0) {
        FUN_00465a06(iVar7);
        FUN_00401f6f();
      }
    }
  }
  return;
}

