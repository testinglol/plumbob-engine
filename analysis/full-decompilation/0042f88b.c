
char * FUN_0042f88b(char *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar6 = *(char **)(param_1 + 8);
  pcVar7 = param_1;
  if (pcVar6 == (char *)0x0) {
    pcVar5 = *(char **)(param_1 + 0xc);
  }
  else {
    pcVar3 = *(char **)(param_1 + 0xc);
    pcVar5 = pcVar6;
    if (*(char **)(param_1 + 0xc) != (char *)0x0) {
      do {
        pcVar7 = pcVar3;
        pcVar3 = *(char **)(pcVar7 + 8);
      } while (*(char **)(pcVar7 + 8) != (char *)0x0);
      pcVar5 = *(char **)(pcVar7 + 0xc);
      if (pcVar7 != param_1) {
        *(char **)(pcVar6 + 4) = pcVar7;
        *(undefined4 *)(pcVar7 + 8) = *(undefined4 *)(param_1 + 8);
        pcVar6 = pcVar7;
        if (pcVar7 != *(char **)(param_1 + 0xc)) {
          pcVar6 = *(char **)(pcVar7 + 4);
          if (pcVar5 != (char *)0x0) {
            *(char **)(pcVar5 + 4) = pcVar6;
          }
          *(char **)(*(int *)(pcVar7 + 4) + 8) = pcVar5;
          *(undefined4 *)(pcVar7 + 0xc) = *(undefined4 *)(param_1 + 0xc);
          *(char **)(*(int *)(param_1 + 0xc) + 4) = pcVar7;
        }
        if ((char *)*param_2 == param_1) {
          *param_2 = pcVar7;
        }
        else {
          iVar2 = *(int *)(param_1 + 4);
          if (*(char **)(iVar2 + 8) == param_1) {
            *(char **)(iVar2 + 8) = pcVar7;
          }
          else {
            *(char **)(iVar2 + 0xc) = pcVar7;
          }
        }
        *(undefined4 *)(pcVar7 + 4) = *(undefined4 *)(param_1 + 4);
        cVar1 = *pcVar7;
        *pcVar7 = *param_1;
        *param_1 = cVar1;
        pcVar7 = param_1;
        goto LAB_0042f979;
      }
    }
  }
  pcVar6 = *(char **)(pcVar7 + 4);
  if (pcVar5 != (char *)0x0) {
    *(char **)(pcVar5 + 4) = pcVar6;
  }
  if ((char *)*param_2 == param_1) {
    *param_2 = pcVar5;
  }
  else {
    iVar2 = *(int *)(param_1 + 4);
    if (*(char **)(iVar2 + 8) == param_1) {
      *(char **)(iVar2 + 8) = pcVar5;
    }
    else {
      *(char **)(iVar2 + 0xc) = pcVar5;
    }
  }
  if ((char *)*param_3 == param_1) {
    if (*(int *)(param_1 + 0xc) == 0) {
      *param_3 = *(undefined4 *)(param_1 + 4);
    }
    else {
      pcVar3 = pcVar5;
      for (pcVar4 = *(char **)(pcVar5 + 8); pcVar4 != (char *)0x0; pcVar4 = *(char **)(pcVar4 + 8))
      {
        pcVar3 = pcVar4;
      }
      *param_3 = pcVar3;
    }
  }
  if ((char *)*param_4 == param_1) {
    if (*(int *)(param_1 + 8) == 0) {
      pcVar3 = *(char **)(param_1 + 4);
    }
    else {
      pcVar3 = pcVar5;
      for (pcVar4 = *(char **)(pcVar5 + 0xc); pcVar4 != (char *)0x0;
          pcVar4 = *(char **)(pcVar4 + 0xc)) {
        pcVar3 = pcVar4;
      }
    }
    *param_4 = pcVar3;
  }
LAB_0042f979:
  if (*pcVar7 == '\0') {
    return pcVar7;
  }
  do {
    if ((pcVar5 == (char *)*param_2) || ((pcVar5 != (char *)0x0 && (*pcVar5 != '\x01'))))
    goto LAB_0042faab;
    pcVar3 = *(char **)(pcVar6 + 8);
    if (pcVar5 == pcVar3) {
      pcVar3 = *(char **)(pcVar6 + 0xc);
      if (*pcVar3 == '\0') {
        *pcVar3 = '\x01';
        *pcVar6 = '\0';
        FUN_0042fab9(pcVar6,param_2);
        pcVar3 = *(char **)(pcVar6 + 0xc);
      }
      if (((*(char **)(pcVar3 + 8) != (char *)0x0) && (**(char **)(pcVar3 + 8) != '\x01')) ||
         ((*(char **)(pcVar3 + 0xc) != (char *)0x0 && (**(char **)(pcVar3 + 0xc) != '\x01')))) {
        if ((*(char **)(pcVar3 + 0xc) == (char *)0x0) || (**(char **)(pcVar3 + 0xc) == '\x01')) {
          if (*(undefined1 **)(pcVar3 + 8) != (undefined1 *)0x0) {
            **(undefined1 **)(pcVar3 + 8) = 1;
          }
          *pcVar3 = '\0';
          FUN_0042faf9(pcVar3,param_2);
          pcVar3 = *(char **)(pcVar6 + 0xc);
        }
        *pcVar3 = *pcVar6;
        *pcVar6 = '\x01';
        if (*(int *)(pcVar3 + 0xc) != 0) {
          **(undefined1 **)(pcVar3 + 0xc) = 1;
        }
        FUN_0042fab9(pcVar6,param_2);
        goto LAB_0042faab;
      }
    }
    else {
      if (*pcVar3 == '\0') {
        *pcVar3 = '\x01';
        *pcVar6 = '\0';
        FUN_0042faf9(pcVar6,param_2);
        pcVar3 = *(char **)(pcVar6 + 8);
      }
      if (((*(char **)(pcVar3 + 0xc) != (char *)0x0) && (**(char **)(pcVar3 + 0xc) != '\x01')) ||
         ((*(char **)(pcVar3 + 8) != (char *)0x0 && (**(char **)(pcVar3 + 8) != '\x01')))) {
        if ((*(char **)(pcVar3 + 8) == (char *)0x0) || (**(char **)(pcVar3 + 8) == '\x01')) {
          if (*(undefined1 **)(pcVar3 + 0xc) != (undefined1 *)0x0) {
            **(undefined1 **)(pcVar3 + 0xc) = 1;
          }
          *pcVar3 = '\0';
          FUN_0042fab9(pcVar3,param_2);
          pcVar3 = *(char **)(pcVar6 + 8);
        }
        *pcVar3 = *pcVar6;
        *pcVar6 = '\x01';
        if (*(int *)(pcVar3 + 8) != 0) {
          **(undefined1 **)(pcVar3 + 8) = 1;
        }
        FUN_0042faf9(pcVar6,param_2);
LAB_0042faab:
        if (pcVar5 == (char *)0x0) {
          return pcVar7;
        }
        *pcVar5 = '\x01';
        return pcVar7;
      }
    }
    *pcVar3 = '\0';
    pcVar5 = pcVar6;
    pcVar6 = *(char **)(pcVar6 + 4);
  } while( true );
}

