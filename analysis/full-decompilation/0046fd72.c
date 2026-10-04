
void __fastcall FUN_0046fd72(int param_1)

{
  undefined2 uVar1;
  size_t sVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  short *psVar8;
  
  iVar6 = 4;
  for (puVar7 = *(undefined4 **)(param_1 + 0x60); puVar7 != *(undefined4 **)(param_1 + 100);
      puVar7 = puVar7 + 1) {
    if ((char *)*puVar7 == (char *)0x0) {
      sVar2 = 0;
    }
    else {
      sVar2 = _strlen((char *)*puVar7);
    }
    iVar6 = iVar6 + sVar2 + 4;
  }
  iVar6 = FUN_0041ffd9(iVar6);
  if (iVar6 == 0) {
    FUN_00633a1e();
  }
  else {
    puVar3 = (undefined2 *)FUN_00420048(iVar6);
    *puVar3 = 0xfffd;
    uVar1 = FUN_0046fbe5(*(undefined1 *)(param_1 + 0x5d));
    puVar3[1] = uVar1;
    psVar8 = puVar3 + 2;
    for (puVar7 = *(undefined4 **)(param_1 + 0x60); puVar7 != *(undefined4 **)(param_1 + 100);
        puVar7 = puVar7 + 1) {
      *psVar8 = *(char *)(param_1 + 0x5d) + 1;
      puVar4 = (undefined1 *)*puVar7;
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_006de560;
      }
      FUN_006358b0((char *)((int)psVar8 + 1),puVar4);
      sVar2 = _strlen((char *)((int)psVar8 + 1));
      *(undefined1 *)((int)psVar8 + sVar2 + 2) = 0;
      psVar8 = (short *)((int)psVar8 + sVar2 + 3);
    }
    FUN_0042004f(iVar6);
    if ((*(int *)(param_1 + 0x58) == 0) || (*(int *)(param_1 + 0x58) == 0x435354)) {
      *(undefined4 *)(param_1 + 0x58) = 0x53545223;
    }
    (**(code **)(**(int **)(param_1 + 4) + 0x74))
              (iVar6,*(undefined4 *)(param_1 + 0x58),
               CONCAT22((short)((uint)(param_1 + 8) >> 0x10),*(undefined2 *)(param_1 + 0x54)),
               param_1 + 8,1);
    iVar5 = FUN_00401f6f();
    if (iVar5 == 0) {
      (**(code **)(**(int **)(param_1 + 4) + 0x7c))(iVar6);
      iVar5 = FUN_00401f6f();
      if (iVar5 == 0) {
        FUN_00465a06(iVar6);
        FUN_00401f6f();
      }
    }
  }
  return;
}

