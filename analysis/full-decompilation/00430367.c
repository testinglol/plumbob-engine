
void FUN_00430367(char *param_1,undefined4 *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  *param_1 = '\0';
  do {
    while( true ) {
      if ((param_1 == (char *)*param_2) || (pcVar1 = *(char **)(param_1 + 4), *pcVar1 != '\0')) {
        *(undefined1 *)*param_2 = 1;
        return;
      }
      pcVar2 = *(char **)(*(int *)(pcVar1 + 4) + 8);
      if (pcVar1 == pcVar2) break;
      if ((pcVar2 == (char *)0x0) || (*pcVar2 != '\0')) {
        if (param_1 == *(char **)(pcVar1 + 8)) {
          FUN_0042faf9(pcVar1,param_2);
          param_1 = pcVar1;
        }
        **(undefined1 **)(param_1 + 4) = 1;
        **(undefined1 **)(*(int *)(param_1 + 4) + 4) = 0;
        FUN_0042fab9(*(undefined4 *)(*(int *)(param_1 + 4) + 4),param_2);
      }
      else {
LAB_004303d2:
        *pcVar1 = '\x01';
        *pcVar2 = '\x01';
        **(undefined1 **)(*(int *)(param_1 + 4) + 4) = 0;
        param_1 = *(char **)(*(int *)(param_1 + 4) + 4);
      }
    }
    pcVar2 = *(char **)(*(int *)(pcVar1 + 4) + 0xc);
    if ((pcVar2 != (char *)0x0) && (*pcVar2 == '\0')) goto LAB_004303d2;
    if (param_1 == *(char **)(pcVar1 + 0xc)) {
      FUN_0042fab9(pcVar1,param_2);
      param_1 = pcVar1;
    }
    **(undefined1 **)(param_1 + 4) = 1;
    **(undefined1 **)(*(int *)(param_1 + 4) + 4) = 0;
    FUN_0042faf9(*(undefined4 *)(*(int *)(param_1 + 4) + 4),param_2);
  } while( true );
}

