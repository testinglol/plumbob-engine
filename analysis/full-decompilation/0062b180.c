
void FUN_0062b180(int param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0xffffffff;
  pcVar5 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  puVar2 = *(undefined1 **)(param_1 + 0x268) + ~uVar4;
  if (param_3 != 0) {
    puVar2 = puVar2 + 1;
  }
  if (0x10000 < (int)puVar2 - *(int *)(param_1 + 0x26c)) {
    if (param_3 == 2) {
      **(undefined1 **)(param_1 + 0x268) = 10;
    }
    puVar3 = (undefined4 *)FUN_005a9320(0x10000);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_00628310(param_1,"Out of memory!\n");
    }
    **(undefined4 **)(param_1 + 0x26c) = puVar3;
    *(undefined4 **)(param_1 + 0x26c) = puVar3;
    *puVar3 = 0;
    *(undefined4 **)(param_1 + 0x268) = puVar3 + 1;
  }
  pcVar5 = *(char **)(param_1 + 0x268);
  cVar1 = *param_2;
  *pcVar5 = cVar1;
  while (pcVar5 = pcVar5 + 1, cVar1 != '\0') {
    param_2 = param_2 + 1;
    cVar1 = *param_2;
    *pcVar5 = cVar1;
  }
  *(char **)(param_1 + 0x268) = pcVar5;
  return;
}

