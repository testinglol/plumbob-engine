
char __thiscall FUN_0053767b(int param_1,int param_2)

{
  short sVar1;
  char cVar2;
  bool bVar3;
  
  cVar2 = '\0';
  bVar3 = *(short *)(*(int *)(param_1 + 0xdc) + 0x60e) == 1;
  sVar1 = *(short *)(*(int *)(param_1 + 0xdc) + 0x600);
  if ((sVar1 != 0) && (sVar1 < 0x12)) {
    if (!bVar3) {
      if (param_2 % 2 == 0) {
        return '5';
      }
      cVar2 = '<';
    }
    if (!bVar3) {
      return cVar2;
    }
    return (-(param_2 % 2 != 0) & 6U) + 0x36;
  }
  if (bVar3) {
LAB_0053770d:
    if (!bVar3) {
      return '\0';
    }
    switch(param_2) {
    case 0:
code_r0x0053771e:
      cVar2 = '0';
      break;
    case 1:
      cVar2 = '+';
      break;
    case 2:
code_r0x005376f3:
      cVar2 = ',';
      break;
    case 3:
      cVar2 = '1';
      break;
    case 4:
code_r0x005376fb:
      cVar2 = '\'';
      break;
    case 5:
      cVar2 = '2';
      break;
    case 6:
      cVar2 = '3';
      break;
    case 7:
      cVar2 = '4';
      break;
    default:
      cVar2 = '\0';
    }
  }
  else {
    switch(param_2) {
    case 0:
      goto code_r0x0053771e;
    case 1:
      cVar2 = ':';
      break;
    case 2:
      goto code_r0x005376f3;
    case 3:
      cVar2 = '-';
      break;
    case 4:
      goto code_r0x005376fb;
    case 5:
      cVar2 = '.';
      break;
    case 6:
      cVar2 = '/';
      break;
    case 7:
      cVar2 = '(';
      break;
    default:
      goto LAB_0053770d;
    }
  }
  return cVar2;
}

